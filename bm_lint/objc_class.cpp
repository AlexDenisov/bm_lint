//
//  objc_class.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/11/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "objc_class.h"
#include "objc_property.h"
#include "objc_protocol.h"

objc_class::objc_class(const std::string &name)
: _name(name)
{
}

objc_class::~objc_class()
{
    auto pit = _properties.begin();
    while (pit != _properties.end()) {
        objc_property *p = *pit;
        pit++;
        delete p;
    }
    
    _properties.clear();
    _protocols.clear();
    _property_map.clear();
}

const std::string &objc_class::name() const
{
    return _name;
}

void objc_class::set_superclass(objc_class *superclass)
{
    _superclass = superclass;
}

objc_class *objc_class::superclass() const
{
    return _superclass;
}

objc_property *objc_class::lookup_property(const std::string &property_name)
{
    objc_property *property = _property_map[property_name];
    if (!property) {
        property = new objc_property(this, property_name);
        _property_map[property_name] = property;
        _properties.push_back(property);
    }
    
    return property;
}

const property_list &objc_class::properties() const
{
    return _properties;
}

const protocol_set &objc_class::protocols() const
{
    return _protocols;
}

void objc_class::add_protocol(objc_protocol *protocol)
{
    _protocols.insert(protocol);
}
