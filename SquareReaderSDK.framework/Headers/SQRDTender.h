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

@class SQRDTenderCardDetails;
@class SQRDTenderCashDetails;
@class SQRDMoney;


/**
 Indicates a tender’s type.
 */
typedef NS_ENUM(NSInteger, SQRDTenderType) {
    /** A tender type that does not match any other value, such as a check. */
    SQRDTenderTypeOther = 0,

    /** A payment card */
    SQRDTenderTypeCard,

    /** Cash */
    SQRDTenderTypeCash,
};

/**
 Represents a tender used during the checkout flow.
 */
@interface SQRDTender : NSObject <NSCopying>

/**
 A unique ID for the tender issued by Square's servers.
 
 Tender IDs can be used to issue refunds with the [Connect v2 Transactions API](https://docs.connect.squareup.com/api/connect/v2/).
 Currently, the tender ID is only present if the `type` is `.card`.
 */
@property (nonatomic, readonly, nullable) NSString *tenderID;

/**
 The date and time when the tender was created, as determined by the client device.
 */
@property (nonatomic, readonly, nonnull) NSDate *createdAt;

/**
 The type of tender.
 */
@property (nonatomic, readonly) SQRDTenderType type;

/**
 The total monetary amount of this tender, including tips.
 */
@property (nonatomic, readonly, nonnull) SQRDMoney *totalMoney;

/**
 The monetary amount added to this tender as a tip.
 
 Included in the total indicated by `totalMoney`.
 */
@property (nonatomic, readonly, nonnull) SQRDMoney *tipMoney;

/**
 Details related to a card payment.
 
 This value is only present if `type` is `.card`.
 */
@property (nonatomic, readonly, nullable) SQRDTenderCardDetails *cardDetails;

/**
 Details related to a cash payment.
 
 This value is only present if `type` is `.cash`.
 */
@property (nonatomic, readonly, nullable) SQRDTenderCashDetails *cashDetails;

#pragma mark - NSObject

/**
 :nodoc:
 Returns a Boolean value that indicates whether the receiver and a given SQRDTender are equal.
 */
- (BOOL)isEqual:(nullable SQRDTender *)object;

/**
 :nodoc:
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

/** :nodoc: */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** :nodoc: */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
