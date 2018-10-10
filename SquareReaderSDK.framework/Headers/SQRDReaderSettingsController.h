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
#import <SquareReaderSDK/SQRDErrorConstants.h>

@class SQRDReaderSettingsController;

/** The reader settings controller error domain. */
extern NSString *_Nonnull const SQRDReaderSettingsControllerErrorDomain;

/** The types of errors that can occur when presenting a `SQRDReaderSettingsController`. */
SQRD_ERROR_ENUM(SQRDReaderSettingsControllerErrorDomain, SQRDReaderSettingsControllerError){
    /**
     `SQRDReaderSettingsController` was used in an unexpected or unsupported way.
     See `userInfo[SQRDErrorDebugCodeKey]` and `userInfo[SQRDErrorDebugMessageKey]` for more information.
     */
    SQRDReaderSettingsControllerErrorUsageError = 1,

    /** Reader SDK is not currently authorized. */
    SQRDReaderSettingsControllerErrorSDKNotAuthorized,
};

/**
 The delegate of a `SQRDReaderSettingsController` object must adopt the `SQRDReaderSettingsControllerDelegate` protocol.
 */
@protocol SQRDReaderSettingsControllerDelegate

/**
 Indicates that the reader settings flow presented successfully.
 @param readerSettingsController The successfully presented `SQRDReaderSettingsController` instance.
 */
- (void)readerSettingsControllerDidPresent:(nonnull SQRDReaderSettingsController *)readerSettingsController;

/**
 Indicates that the reader settings flow failed to present.
 @param readerSettingsController The `SQRDReaderSettingsController` instance that failed to present.
 @param error An error in the `SQRDReaderSettingsControllerErrorDomain`.
              See `SQRDReaderSettingsControllerError` for possible error types.
 */
- (void)readerSettingsController:(nonnull SQRDReaderSettingsController *)readerSettingsController didFailToPresentWithError:(nonnull NSError *)error NS_SWIFT_NAME(readerSettingsController(_:didFailToPresentWith:));
@end

/**
 Lets the application present screens for connecting and managing a set of Square Readers.
 */
@interface SQRDReaderSettingsController : NSObject

/**
 Create a new `SQRDReaderSettingsController` with the specified delegate.
 
 @param delegate The object that acts as the delegate of the reader settings controller.
 */
- (nonnull instancetype)initWithDelegate:(nonnull id<SQRDReaderSettingsControllerDelegate>)delegate;

/**
 Presents a view controller for connecting and managing Square Readers.
 
 @param viewController The view controller from which the reader settings flow will be modally presented.
 @note Reader SDK must be authorized to present the reader settings flow.
 @note This method must be called from the main thread.
 */
- (void)presentFromViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(present(from:));

/**
 :nodoc:
 `init` is unavailable. Use `initWithDelegate:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 `new` is unavailable. Use `initWithDelegate:` instead.
 */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
