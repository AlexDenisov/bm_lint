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
        
        it("should have name", {
            expect(test_class->name()).should.equal("test");
        });
        
        it("should have superclass", {
            expect(test_class->superclass()).shouldNot.beNil();
        });
        
        it("should have right superclass", {
#warning waiting for base class parsing implementation
            expect(false).should.beTrue();
            // expect(test_class->superclass()->name()).should.equal("root");
        });
        
        it("should have properties", {
            expect(test_class->properties()).should.haveCountOf(3);
        });
        
        it("should have dynamic properties", {
            expect(test_class->dynamic_properties()).should.haveCountOf(1);
        });
        
        it("should have protocols", {
            expect(test_class->protocols()).should.haveCountOf(2);
        });
        
    });
    
});
