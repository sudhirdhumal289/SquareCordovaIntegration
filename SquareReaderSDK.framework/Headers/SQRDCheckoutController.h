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

#import <UIKit/UIKit.h>
#import "SQRDErrorConstants.h"

@class SQRDCheckoutController;
@class SQRDCheckoutParameters;
@class SQRDCheckoutResult;

/** The checkout controller error domain. */
extern NSString *_Nonnull const SQRDCheckoutControllerErrorDomain;

/** The types of errors that can occur when presenting a `SQRDCheckoutController`. */
SQRD_ERROR_ENUM(SQRDCheckoutControllerErrorDomain, SQRDCheckoutControllerError){
    /**
     `SQRDCheckoutController` was used in an unexpected or unsupported way.
     See `userInfo[SQRDErrorDebugCodeKey]` and `userInfo[SQRDErrorDebugMessageKey]` for more information.
     */
    SQRDCheckoutControllerErrorUsageError = 1,

    /** Reader SDK is not currently authorized. */
    SQRDCheckoutControllerErrorSDKNotAuthorized,
};

/**
 The delegate of a `SQRDCheckoutController` object must adopt the `SQRDCheckoutControllerDelegate` protocol.
 */
@protocol SQRDCheckoutControllerDelegate <NSObject>


/**
 Indicates that the checkout flow succeeded.
 
 @param checkoutController The checkout controller instance that finished checkout.
 @param result The result of the completed transaction.
 */
- (void)checkoutController:(nonnull SQRDCheckoutController *)checkoutController didFinishCheckoutWithResult:(nonnull SQRDCheckoutResult *)result;

/**
 Indicates that the checkout flow failed.
 
 @param checkoutController The checkout controller instance that failed with an error.
 @param error An error in the `SQRDCheckoutControllerErrorDomain`.
              See `SQRDCheckoutControllerError` for possible error types.
 */
- (void)checkoutController:(nonnull SQRDCheckoutController *)checkoutController didFailWithError:(nonnull NSError *)error NS_SWIFT_NAME(checkoutController(_:didFailWith:));

/**
 Indicates that checkout was cancelled.
 
 @param checkoutController The checkout controller instance that was cancelled.
 */
- (void)checkoutControllerDidCancel:(nonnull SQRDCheckoutController *)checkoutController;

@end

/**
 Lets the application collect payment from customers using Square's checkout flow.
 */
@interface SQRDCheckoutController : NSObject

/**
 Creates a new checkout controller.
 
 @param parameters The parameters needed to start a checkout, including the amount of the transaction.
 @param delegate The object that acts as the delegate of the checkout controller.
 */
- (nonnull instancetype)initWithParameters:(nonnull SQRDCheckoutParameters *)parameters
                                  delegate:(nonnull id<SQRDCheckoutControllerDelegate>)delegate;

/**
 Presents a view controller for the checkout flow.
 
 @param viewController The view controller from which the checkout flow should be modally presented.
 @note Reader SDK must be authorized to present the checkout flow.
 @note This method must be called from the main thread.
 */
- (void)presentFromViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(present(from:));

#pragma mark - NSObject

/**
 :nodoc:
 `init` is unavailable. Use `initWithParameters:delegate:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 `new` is unavailable. Use `initWithParameters:delegate:` instead.
 */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
