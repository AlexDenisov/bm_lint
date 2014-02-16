//
//  parser.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "objc_definitions.h"

class parser
{
public:
    explicit parser(ast *ast);
    void parse(const std::string &filename);
    
    void handle_objc_class(const std::string &name);
    void handle_objc_super_class(const std::string &name);
    void handle_objc_property(const std::string &name);
    void handle_objc_dynamic(const std::string &name);
    void handle_annotation(const std::string &name);
    
private:
    ast *_ast;
    
    // bethink about context
    objc_class *_current_class;
    objc_property *_current_property;
};
