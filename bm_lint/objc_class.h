//
//  objc_class.h
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "objc_definitions.h"

class objc_class
{
public:
    explicit objc_class(const std::string &name);
    ~objc_class();
    
    const std::string &name() const;
    
    // superclass
    void set_superclass(objc_class *superclass);
    objc_class *superclass() const;
    
    // properties
    objc_property *lookup_property(const std::string &property_name);
    const property_list &properties() const;
    const property_list &dynamic_properties() const;
    
    // protocols
    const protocol_list &protocols() const;
    void add_protocol(objc_protocol *protocol);
private:
    std::string _name;
    objc_class *_superclass;
    property_map _property_map;
    property_list _properties;
    protocol_list _protocols;
};
