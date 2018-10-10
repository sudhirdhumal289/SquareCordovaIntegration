//
//	Copyright (c) 2018-present, Square, Inc. All rights reserved.
//
//	Your use of this software is subject to the Square Developer Terms of
//	Service (https://squareup.com/legal/developers). This copyright notice shall
//	be included in all copies or substantial portions of the software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//

#import <UIKit/UIApplication.h>
#import <SquareReaderSDK/SQRDErrorConstants.h>

@class SQRDLocation;

/**
  A completion handler that handles the result of an authorization attempt.
  @param location The authorized location when authorization succeeds, `nil` when authorization fails.
  @param error An error with domain `SQRDAuthorizationErrorDomain` when authorization fails; otherwise, `nil`.
               See `SQRDAuthorizationError` for possible error types.
 */
typedef void (^SQRDAuthorizationHandler)(SQRDLocation *_Nullable location, NSError *_Nullable error);

/** The authorization error domain. */
extern NSString *_Nonnull const SQRDAuthorizationErrorDomain;

/** The types of errors that can occur when attempting to authorize Reader SDK. */
SQRD_ERROR_ENUM(SQRDAuthorizationErrorDomain, SQRDAuthorizationError){
    /**
     `authorize` was used in an unexpected or unsupported way.
     See userInfo[SQRDErrorDebugCodeKey] and userInfo[SQRDErrorDebugMessageKey] for more information.
    */
    SQRDAuthorizationErrorUsageError = 1,

    /** Reader SDK could not connect to the network. */
    SQRDAuthorizationErrorNoNetworkConnection,
};

/**
 A completion handler that handles the result of a deauthorization attempt.
 @param error An error with domain `SQRDDeauthorizationErrorDomain` when deauthorization fails; otherwise, `nil`.
              See `SQRDDeauthorizationError` for possible error types.
 */
typedef void (^SQRDDeauthorizationHandler)(NSError *_Nullable error);

/** The deauthorization error domain. */
extern NSString *_Nonnull const SQRDDeauthorizationErrorDomain;

/** The types of errors that can occur when attempting to deauthorize Reader SDK. */
SQRD_ERROR_ENUM(SQRDDeauthorizationErrorDomain, SQRDDeauthorizationError){
    /**
     `deauthorize` was used in an unexpected or unsupported way.
     See userInfo[SQRDErrorDebugCodeKey] and userInfo[SQRDErrorDebugMessageKey] for more information.
     */
    SQRDDeauthorizationErrorUsageError = 1,
};

/**
 Manages initialization and authorization for Reader SDK.
 @warning You must initialize Reader SDK before attempting any other operation.
 @see SQRDReaderSettingsController
 @see SQRDCheckoutController
 */
@interface SQRDReaderSDK : NSObject

/**
 Initializes Reader SDK.
 Call this method from the `application:didFinishLaunchingWithOptions:` method in your app delegate.
 @warning You must initialize Reader SDK before attempting any other operation, or your app will crash.
 */
+ (void)initializeWithApplicationLaunchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;

/**
 The Reader SDK singleton.
 Use this to authorize and deauthorize Reader SDK to accept payments on behalf of a Square seller account.
 */
@property (class, readonly, strong, nonnull) SQRDReaderSDK *sharedSDK;

/**
 Returns the location of the authorized Square seller account if Reader SDK is authorized; otherwise, `nil`.
 */
@property (nonatomic, readonly, strong, nullable) SQRDLocation *authorizedLocation;

#pragma mark - Authorization

/**
 Authorize the SDK with a mobile authorization code.
 @param code The mobile authorization code used to authorize the SDK for a Square merchant.
 @param completionHandler The completion handler to be called upon success or failure of the authorization attempt.
 */
- (void)authorizeWithCode:(nonnull NSString *)code completionHandler:(nonnull SQRDAuthorizationHandler)completionHandler;

/// Returns `true` if Reader SDK is currently authorized to accept payments on behalf of a Square seller account; otherwise, `false`.
@property (nonatomic, readonly) BOOL isAuthorized;

/// Returns `true` if a Reader SDK authorization is in progress, `false` otherwise.
@property (nonatomic, readonly) BOOL isAuthorizationInProgress;

#pragma mark - Deauthorization

/**
 Deauthorize the SDK.
 @param completionHandler The completion handler to be called upon success or failure of the deauthorization attempt.
 @note Deauthorization may fail if there are pending uploads that need to be completed (for instance, uploading a payment to Square). You can always check if deauthorization is possible by checking the `canDeauthorize` property on the SDK singleton.
 */
- (void)deauthorizeWithCompletionHandler:(nonnull SQRDDeauthorizationHandler)completionHandler;

/**
 Returns `true` if Reader SDK is currently authorized and there are no pending uploads; otherwise, `false`.
 Deauthorization fails if there are asynchronous payments recorded on the device that have not been uploaded to Square servers.
 This can happen when the device is having network connection issues.
 */
@property (nonatomic, readonly) BOOL canDeauthorize;

/** 
  :nodoc:
  `init` is unavailable. Use `sharedSDK` instead.
  */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** 
  :nodoc:
  `new` is unavailable. Use `sharedSDK` instead. 
  */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
