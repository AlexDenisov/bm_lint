//
//  objc_protocol.h
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "objc_definitions.h"

class objc_protocol
{
public:
    explicit objc_protocol(const std::string &protocol_name);
    
    const std::string name() const;
    
    const class_list &clasess() const;
    void add_class(objc_class *objc_class);
    
private:
    std::string _name;
    class_list _classes;
};
