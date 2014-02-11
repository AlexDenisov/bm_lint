//
//  ast_test.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "ZingBDD.h"

#include "ast.h"
#include "parser.h"
#include "objc_class.h"

describe(parser_tests, {
    ast *sut;
    
    beforeEach({
        sut = new ast;
        parser p(sut);
        p.parse("test.m");
    });
    
    afterEach({
        delete sut;
    });
    
    it("should parse all classes", {
        expect(sut->objc_classes()).should.haveCountOf(2);
    });
    
    context("test class", {
        objc_class *test_class;
        
        beforeEach({
            test_class = sut->lookup_class("test");
        });
        
        it("should not be NULL", {
            expect(test_class).should.beNonNil();
        });
        
        it("should parse name", {
            expect(test_class->name()).should.equal("test");
        });
        
    });
    
});
