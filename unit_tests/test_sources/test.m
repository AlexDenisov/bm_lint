//
//  test.m
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

__attribute__((objc_root_class))
@interface root
@end
@implementation root
@end

@protocol test_protocol
@end

@protocol another_test_protocol
@end

@interface test : root
    <test_protocol>

@property (nonatomic, strong) __attribute__((annotate("red_property"))) root *red;
@property (nonatomic, strong) root *green;
@property (nonatomic, strong) root *blue;

@end

@interface test ()
    <test_protocol,
    another_test_protocol>

@end

@implementation test

@dynamic red;

@end
