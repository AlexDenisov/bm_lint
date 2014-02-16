//
//  objc_category.h
//  bm_lint
//
//  Created by AlexDenisov on 2/16/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "definitions.h"

class objc_category
{
public:
    objc_category(const std::string &name);
    const std::string &name() const;
    
private:
    std::string _name;
};
