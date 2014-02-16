//
//  objc_property.h
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include "definitions.h"

class objc_property
{
public:
    explicit objc_property(objc_class *objc_class, const std::string &name);
    
    const std::string &name() const;
    objc_class *container_class() const;
    
    void set_dynamic(bool dynamic);
    bool is_dynamic() const;
    
    void add_annotation(annotation *annotation);
    const annotation_list &annotations() const;
    
private:
    std::string _name;
    bool _dynamic;
    objc_class *_class;
    annotation_list _annotations;
};
