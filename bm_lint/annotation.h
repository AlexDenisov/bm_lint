//
//  annotation.h
//  bm_lint
//
//  Created by AlexDenisov on 2/16/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "objc_definitions.h"

class annotation
{
public:
    annotation(const std::string &name);
    
    const std::string &name() const;
    
private:
    std::string _name;
};
