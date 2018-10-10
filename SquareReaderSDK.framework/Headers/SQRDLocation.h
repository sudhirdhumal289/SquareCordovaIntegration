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

#import <Foundation/Foundation.h>
#import <SquareReaderSDK/SQRDCurrencyCode.h>

@class SQRDMoney;

/**
 Represents a [Square location](https://docs.connect.squareup.com/api/connect/v2#type-location).
 */
@interface SQRDLocation : NSObject <NSCopying>

/**
 The unique identifier for the location.
 */
@property (nonatomic, strong, readonly, nonnull) NSString *locationID;

/**
 The name of the location (displayed as the location's nickname in Square Dashboard).
 */
@property (nonatomic, strong, readonly, nonnull) NSString *name;

/**
 The business name associated with the location. This is the name shown on Square digital receipts.
 */
@property (nonatomic, strong, readonly, nonnull) NSString *businessName;

/**
 Indicates whether or not this location is activated for card processing.
 */
@property (nonatomic, readonly) BOOL isCardProcessingActivated;

/**
 The minimum card payment amount for this location.
 */
@property (nonatomic, strong, readonly, nonnull) SQRDMoney *minimumCardPaymentAmountMoney;

/**
 The maximum card payment amount for this location.
 */
@property (nonatomic, strong, readonly, nonnull) SQRDMoney *maximumCardPaymentAmountMoney;

/**
 The currency used for all transactions at this location, specified as a `SQRDCurrencyCode`.
 */
@property (nonatomic, readonly) SQRDCurrencyCode currencyCode;

#pragma mark - NSObject

/**
 Returns a Boolean value that indicates whether the receiver and a given `SQRDLocation` are equal.
 */
- (BOOL)isEqual:(nullable SQRDMoney *)object;

/**
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

/** :nodoc: */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** :nodoc: */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
