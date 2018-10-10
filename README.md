# Cordova Square Reader SDK

A Cordova plugin to interface with the native Square Reader POS SDKs.

# Install

`$ cordova plugin add cordova-plugin-square-reader`

`$ cordova platform ios prepare` 

## Install the Square SDK

Square Reader SDK is included in the plugin. But it is recommended to upgrade the SDK.
Currently we only support iOS.

For more details refer [Square Reader SDK Documentation](https://docs.connect.squareup.com/payments/readersdk/setup-ios).
Step 2 can be skipped as plugins comes with integrated Square Reader SDK.
Sub Step from Step 3 - "Update your Info.plist" can be skipped. Plugin will auto configure this.

## Pair the card reader

```javascript
window['squarereader'].setup(function () {
    console.log("SquareReaderSDK initiated")
}, function (err) {
    console.error("SquareReaderSDK initialization failed.");
    console.error(err);
});
```

## Authorize and checkout

```javascript
var retrieveAuthParams = {
    "personalAccessToken": "<YOUR PERSONAL ACCESS TOKEN>",
    "locationId": "<LOCATION ID OF>"
};
window['squarereader'].retrieveAuthorizationCode(retrieveAuthParams, function (response) {
    console.log("Application authorization code: " + response.authorization_code);

    var authorizeParams = {
        "authCode": response.authorization_code
    };

    window['squarereader'].authorizeReaderSDKIfNeeded(authorizeParams, function () {
        console.log("Application is authorized.");

        let checkoutParam = {
            "amount": "1"
        }
        window['squarereader'].startCheckout(checkoutParam, function (response) {
            console.log(response);
            console.log("Checkout completed successfully.");
        }, function (err) {
            console.error("Failed to checkout");
            console.error(err);
        });
    }, function (err) {
        console.log("Failed to authorize with retrieved authorization code.");
    });
}, function (err) {
    console.log('Failed to get the authorization code');
});
```
## NOTE:

Make sure that you are passing the amount in checkout as a string and not number.