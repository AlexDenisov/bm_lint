//
//  ast.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include <map>
#include <string>

class objc_class;

typedef std::map<std::string, objc_class *> class_map;

class ast
{
public:
    objc_class *lookup_class(const std::string &class_name);

    const class_map &objc_classes() const;
    
private:
    class_map _classes;
};
