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

/**
 Settings that configure tipping behavior of the checkout flow.
 
 Default values:
 - `showSeparateTipScreen`: `false`
 - `showCustomTipField`: `false`
 - `tipPercentages`: `[15, 20, 25]`
 
 @see SQRDCheckoutParameters
 
 */
@interface SQRDTipSettings : NSObject <NSCopying>

/**
 Create a `SQRDTipSettings` with default values.
 */
- (nonnull instancetype)init;

/**
 Indicates whether tip options should be presented on their own screen before presenting the signature screen during card transactions.
 
 By default, tip options are displayed on the signature screen.
 */
@property (nonatomic, assign) BOOL showSeparateTipScreen;

/**
 Indicates whether custom tip amounts are allowed during the checkout flow.
 
 Custom tips are disabled by default.
 */
@property (nonatomic, assign) BOOL showCustomTipField;

/**
 A list of tip percentages that should be presented during the checkout flow.
 
 Specified as up to 3 non-negative integers from 0 to 100 (inclusive).
 Defaults to [15, 20, 25], which corresponds to tip percentages of 15%, 20% and 25%.
 */
@property (nonatomic, copy, nonnull) NSArray<NSNumber *> *tipPercentages;

#pragma mark - NSObject

/**
 :nodoc:
 Returns a Boolean value that indicates whether the receiver and a given SQRDTipSettings object are equal.
 */
- (BOOL)isEqual:(nullable SQRDTipSettings *)object;

/**
 :nodoc:
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

@end
