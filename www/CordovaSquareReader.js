function CordovaSquareReader() {
}

CordovaSquareReader.prototype.retrieveAuthorizationCode = function (params, successCallback, errorCallback) {
  cordova.exec(successCallback, errorCallback, "CordovaSquareReader", "retrieveAuthorizationCode", [params]);
};

CordovaSquareReader.prototype.authorizeReaderSDKIfNeeded = function (params, successCallback, errorCallback) {
  cordova.exec(successCallback, errorCallback, "CordovaSquareReader", "authorizeReaderSDKIfNeeded", [params]);
};

CordovaSquareReader.prototype.startCheckout = function (params, successCallback, errorCallback) {
  cordova.exec(successCallback, errorCallback, "CordovaSquareReader", "startCheckout", [params]);
};

CordovaSquareReader.prototype.pairCardReaders = function (successCallback, errorCallback) {
  cordova.exec(successCallback, errorCallback, "CordovaSquareReader", "pairCardReaders", []);
};

CordovaSquareReader.prototype.setup = function (successCallback, errorCallback) {
  cordova.exec(successCallback, errorCallback, "CordovaSquareReader", "setup", []);
};

CordovaSquareReader.install = function () {
  window.squarereader = new CordovaSquareReader();

  return window.squarereader;
};

cordova.addConstructor(CordovaSquareReader.install);
