import SquareReaderSDK
import CoreLocation
import AVKit

@objc(CordovaSquareReader) class CordovaSquareReader : CDVPlugin, SQRDCheckoutControllerDelegate, SQRDReaderSettingsControllerDelegate, CLLocationManagerDelegate {
    private lazy var locationManager = CLLocationManager()
    private var currentCommand: CDVInvokedUrlCommand?
    private var locationPermissionCallback: ((Bool) -> ())?
    var authorizationCode: String = ""
    
    override func pluginInitialize() {
        SQRDReaderSDK.initialize(applicationLaunchOptions: nil)
        
        locationManager.delegate = self
        
        self.requestLocationPermission()
    }
    
    func requestLocationPermission() {
        let locationStatus = CLLocationManager.authorizationStatus()
        let isLocationAccessGranted = (locationStatus == .authorizedWhenInUse || locationStatus == .authorizedAlways)
        
        if(isLocationAccessGranted) {
            // Get microphone permission as location permission is already granted.
            self.requestMicrophonePermission()
        } else {
            // Permission is not given yet, so ask for the location permission
            self.locationManager.requestWhenInUseAuthorization()
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch CLLocationManager.authorizationStatus() {
        case .denied, .restricted:
            print("Location permission denied.")
            
            // Permission denied - Square SDK needs this permission so ask again.
            self.requestLocationPermission()
        case .authorizedAlways, .authorizedWhenInUse:
            print("Location services have already been authorized.")
            
            // Get microphone permission after location permission
            self.requestMicrophonePermission()
        case .notDetermined:
            print("Location permission is not determined yet.")
        }
    }

    func requestMicrophonePermission() {
        AVAudioSession.sharedInstance().requestRecordPermission { authorized in
            if !authorized {
                print("Microphone permission denied.")
                
                // Square SDK require Microphone permission so ask again.
                self.requestMicrophonePermission()
            } else {
                print("Microphone permission granted.")
            }
        }
    }
    
    @objc(retrieveAuthorizationCode:)
    func retrieveAuthorizationCode(command: CDVInvokedUrlCommand) -> String {
        // If already authorized then do not authorize again.
        if SQRDReaderSDK.shared.isAuthorized {
            return self.authorizationCode
        }
        
        self.authorizationCode = ""
        
        guard let commandParams = command.arguments.first as? [String: Any],
            let personalAccessToken = commandParams["personalAccessToken"] as? String else {
                self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: "No personal access token passed"), callbackId: command.callbackId)
                
                return self.authorizationCode
        }
        
        guard let commandParamsTwo = command.arguments.first as? [String: Any],
            let locationId = commandParamsTwo["locationId"] as? String else {
                self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: "No location ID specified"), callbackId: command.callbackId)
                
                return self.authorizationCode
        }
        
        let parameters = ["location_id": locationId]
        
        let url = URL(string: "https://connect.squareup.com/mobile/authorization-code")!
        
        //create the session object
        let session = URLSession.shared
        
        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        
        do {
            request.httpBody = try JSONSerialization.data(withJSONObject: parameters, options: .prettyPrinted)
        } catch let error {
            print(error.localizedDescription)
        }
        
        request.addValue("application/json", forHTTPHeaderField: "Content-Type")
        request.addValue("application/json", forHTTPHeaderField: "Accept")
        request.addValue("Bearer " + personalAccessToken, forHTTPHeaderField: "Authorization")
        
        //create dataTask using the session object to send data to the server
        let task = session.dataTask(with: request as URLRequest, completionHandler: { data, response, error in
            
            guard error == nil else {
                return
            }
            
            guard let data = data else {
                return
            }
            
            do {
                //create json object from data
                if var json = try JSONSerialization.jsonObject(with: data, options: .mutableContainers) as? [String: Any] {
                    print(json)
                    
                    if json["authorization_code"] != nil {
                        self.authorizationCode = json["authorization_code"] as! String
                    } else if json["message"] != nil {
                        self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: json["message"] as? String), callbackId: command.callbackId)
                        return;
                    }
                    
                    self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_OK, messageAs: json), callbackId: command.callbackId)
                }
            } catch let error {
                print(error.localizedDescription)
                
                self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: error.localizedDescription), callbackId: command.callbackId)
            }
        })
        
        task.resume()
        
        return self.authorizationCode
    }
    
    @objc(authorizeReaderSDKIfNeeded:)
    func authorizeReaderSDKIfNeeded(command: CDVInvokedUrlCommand) {
        if SQRDReaderSDK.shared.isAuthorized {
            print("Already authorized.")
            self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_OK), callbackId: command.callbackId)
        } else {
            guard let commandParams = command.arguments.first as? [String: Any],
                let authCode = commandParams["authCode"] as? String else {
                    self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: "No parameters"), callbackId: command.callbackId)
                    return
            }
            SQRDReaderSDK.shared.authorize(withCode: authCode) { location, error in
                if let authError = error {
                    // Handle the error
                    print(authError)
                    self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: authError.localizedDescription), callbackId: command.callbackId)
                }
                else {
                    // Proceed to the main application interface.
                    self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_OK), callbackId: command.callbackId)
                }
            }
        }
    }
    
    @objc(startCheckout:)
    func startCheckout(command: CDVInvokedUrlCommand) {
        guard let commandParams = command.arguments.first as? [String: String] else {
            self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: "No parameters"), callbackId: command.callbackId)
            return
        }
        
        // Convert any to string then convert string to float tand multiply by 100 to convert dollars to cents.
        let amountStr:String = commandParams["amount"] ?? "0"
        let numberFormatter = NumberFormatter()
        var amountFlt:Float = numberFormatter.number(from: amountStr)?.floatValue ?? 0
        //var amountFlt:Float = Float(amountStr) ?? 0
        amountFlt = amountFlt * 100;
        
        let amount:Int = Int(amountFlt)
        
        // Create an amount of money in the currency of the authorized Square account
        let amountMoney = SQRDMoney(amount: amount)
        
        // Create parameters to customize the behavior of the checkout flow.
        let params = SQRDCheckoutParameters(amountMoney: amountMoney)
        params.additionalPaymentTypes = [.manualCardEntry, .cash, .other]
        
        // Create a checkout controller and call present to start checkout flow.
        let checkoutController = SQRDCheckoutController(
            parameters: params,
            delegate: self)
        
        self.currentCommand = command
        
        checkoutController.present(from: self.viewController)
    }
    
    @objc(checkoutControllerDidCancel:)
    func checkoutControllerDidCancel(
        _ checkoutController: SQRDCheckoutController) {
        print("Checkout cancelled.")
        guard let currentCommand = self.currentCommand else {
            return
        }
        self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: "Cancelled"), callbackId: currentCommand.callbackId)
        self.currentCommand = nil
    }
    
    @objc(checkoutController:didFailWithError:)
    func checkoutController(
        _ checkoutController: SQRDCheckoutController, didFailWith error: Error) {
        guard let currentCommand = self.currentCommand else {
            return
        }
        self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: error.localizedDescription), callbackId: currentCommand.callbackId)
        self.currentCommand = nil
    }
    
    @objc(checkoutController:didFinishCheckoutWithResult:)
    func checkoutController(
        _ checkoutController: SQRDCheckoutController,
        didFinishCheckoutWith result: SQRDCheckoutResult) {
        guard let currentCommand = self.currentCommand else {
            return
        }
        
        let amountCollected:Float = Float(result.totalMoney.amount) / 100;
        let checkoutResultDict: NSDictionary = ["transactionClientID": result.transactionClientID,
                                                "transactionID": result.transactionID,
                                                "locationID": result.locationID,
                                                "amountCollected": amountCollected]
        do {
            let JSONPayload: Data = try JSONSerialization.data(withJSONObject: checkoutResultDict, options: JSONSerialization.WritingOptions.prettyPrinted)
            let JSONString = String(data: JSONPayload, encoding: String.Encoding.utf8)
            self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_OK, messageAs: JSONString), callbackId: currentCommand.callbackId)
        } catch let error {
            self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: error.localizedDescription), callbackId: currentCommand.callbackId)
        }
        
        self.currentCommand = nil
    }
    
    @objc(pairCardReaders:)
    func pairCardReaders(command: CDVInvokedUrlCommand) {
        let readerSettingsController = SQRDReaderSettingsController(
            delegate: self
        )
        
        self.currentCommand = command
        
        readerSettingsController.present(from: self.viewController)
    }
    
    @objc(readerSettingsControllerDidPresent:)
    func readerSettingsControllerDidPresent(
        _ readerSettingsController: SQRDReaderSettingsController) {
        print("Reader settings flow presented.")
        
        guard let currentCommand = self.currentCommand else {
            return
        }
        self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_OK), callbackId: currentCommand.callbackId)
        
        self.currentCommand = nil
    }
    
    @objc(readerSettingsController:didFailToPresentWithError:)
    func readerSettingsController(
        _ readerSettingsController: SQRDReaderSettingsController,
        didFailToPresentWith error: Error) {
        print("Failed to present reader settings flow.")
        
        guard let currentCommand = self.currentCommand else {
            return
        }
        self.commandDelegate.send(CDVPluginResult(status: CDVCommandStatus_ERROR, messageAs: error.localizedDescription), callbackId: currentCommand.callbackId)
        
        self.currentCommand = nil
    }
}
