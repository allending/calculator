//
//  CalculatorBrain.h
//  mycalulator
//
//  Created by Sojin Kim on 13. 1. 21..
//  Copyright (c) 2013년 Sojin Kim. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    brainState_init, brainState_left, brainState_op, brainState_right
} brainState;

typedef enum {
    inputType_digit, inputType_operator, inputType_enter, inputType_sign, inputType_decimal, inputType_clear
} inputType;

@interface CalculatorBrain : NSObject
@property (nonatomic) double memoryStore;
@property (nonatomic) NSString *inputString;

- (void)initialize;
- (void)dropCurrentCalculation;

- (void)processDigit:(int)digit;
- (void)processOperator:(int)op;
- (void)processEnter;
- (void)processSign;
- (void)processDecimal;

- (double)performOperation;  // returns result

- (int)operatorString;
- (double)leftOperand;
- (double)rightOperand;

- (void)stateTransitionTo:(brainState)state withInitialValue:(double)value causedBy:(inputType)input;

- (brainState)getCurrentBrainState;
@end
