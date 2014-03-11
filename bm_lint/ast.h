//
//  ast.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "definitions.h"

class ast
{
public:
    ~ast();
    
    objc_class *lookup_class(const std::string &class_name);
    objc_protocol *lookup_protocol(const std::string &protocol_name);
    annotation *lookup_annotation(const std::string &annotation_name);
    objc_category *lookup_category(const std::string &category_name);

    const class_map objc_classes() const;
    const protocol_map objc_protocols() const;
private:
    class_map _class_map;
    protocol_map _protocol_map;
    annotation_map _attribute_map;
    category_map _category_map;
};
