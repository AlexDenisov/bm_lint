//
//  parser.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

class ast;

class parser
{
public:
    explicit parser(ast *ast);
    void parse(const char *filename);
    
private:
    ast *_ast;
};
