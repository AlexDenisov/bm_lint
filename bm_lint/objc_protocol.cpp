//
//  objc_protocol.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "objc_protocol.h"

objc_protocol::objc_protocol(const std::string &protocol_name)
: _name(protocol_name)
{
}

const std::string objc_protocol::name() const
{
    return _name;
}

const class_list &objc_protocol::clasess() const
{
    return _classes;
}

void objc_protocol::add_class(objc_class *objc_class)
{
    _classes.push_back(objc_class);
}