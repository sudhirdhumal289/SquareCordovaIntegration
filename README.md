# Cordova Square Reader SDK

A Cordova plugin to interface with the native Square Reader POS SDKs.

# Install

`$ cordova plugin add cordova-plugin-square-reader`

`$ cordova platform ios prepare` 

## Install the Square SDK

Currently we only support iOS.

For more details refer [Square Reader SDK Documentation](https://docs.connect.squareup.com/payments/readersdk/setup-ios).

Sub Step from Step 3 - "Update your Info.plist" can be skipped. Plugin will auto configure this.

## Pair the card reader

```javascript
window['squarereader'].pairCardReaders(function () {
    console.log('Square card reader completed.');
}, function (err) {
    console.error('Square card reader pairing failed.');
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
            "amount": "<AMOUNT_TO_AUTHORIZE"
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