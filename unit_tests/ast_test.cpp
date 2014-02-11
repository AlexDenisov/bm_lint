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

describe(ast_test, {
    ast *sut;
    
    beforeEach({
        sut = new ast;
        parser p(sut);
        p.parse("test.m");
    });
    
    afterEach({
        delete sut;
    });
    
    it("should find all classes", {
        expect(sut->objc_classes()).should.haveCountOf(2);
    });
    
});
