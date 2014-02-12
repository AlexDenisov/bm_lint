//
//  objc_property.cpp
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#include "objc_property.h"

objc_property::objc_property(objc_class *objc_class, const std::string &name)
: _class(objc_class), _name(name)
{
}

const std::string &objc_property::name() const
{
    return _name;
}

objc_class *objc_property::container_class() const
{
    return _class;
}