//
//  objc_property.h
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "objc_definitions.h"

class objc_property
{
public:
    explicit objc_property(objc_class *objc_class, const std::string &name);
    
    const std::string &name() const;
    objc_class *container_class() const;
    
private:
    std::string _name;
    objc_class *_class;
};
