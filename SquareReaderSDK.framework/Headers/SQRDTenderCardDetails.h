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

@class SQRDCard;

/**
 The entry method used to provide a card's details.
 */
typedef NS_ENUM(NSInteger, SQRDTenderCardDetailsEntryMethod) {
    /** The entry method is unknown. */
    SQRDTenderCardDetailsEntryMethodUnknown = 0,

    /** The card was swiped through a Square Reader or Square Stand. */
    SQRDTenderCardDetailsEntryMethodSwipe,

    /** The card was processed as a chip card transaction (EMV) with a Square Reader. */
    SQRDTenderCardDetailsEntryMethodChip,

    /** The card was processed as a contactless transaction (NFC) with a Square Reader. */
    SQRDTenderCardDetailsEntryMethodContactless,

    /** The card information was typed in manually. */
    SQRDTenderCardDetailsEntryMethodManuallyEntered,
};

/**
 Represents the details related to a card payment.
 */
@interface SQRDTenderCardDetails : NSObject <NSCopying>

/**
 Details about the card used in this tender, such as the brand and last four digits of the card number.
 */
@property (nonatomic, readonly, nonnull) SQRDCard *card;

/**
 The method used to capture the card information during the checkout flow.
 
 For example, whether the card was swiped or typed in manually.
 */
@property (nonatomic, readonly) SQRDTenderCardDetailsEntryMethod entryMethod;

#pragma mark - NSObject

/**
 :nodoc:
 Returns a Boolean value that indicates whether the receiver and a given SQRDTenderCardDetails are equal.
 */
- (BOOL)isEqual:(nullable SQRDTenderCardDetails *)object;

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
