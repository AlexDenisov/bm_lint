//
//  objc_definitions.h
//  bm_lint
//
//  Created by AlexDenisov on 2/12/14.
//  Copyright (c) 2014 Railsware. All rights reserved.
//

#pragma once

#include <string>
#include <map>
#include <vector>

class ast;
class objc_class;
class objc_property;
class objc_protocol;
class annotation;

typedef std::map<std::string, objc_class *> class_map;
typedef std::map<std::string, objc_protocol *> protocol_map;
typedef std::map<std::string, objc_property *> property_map;
typedef std::map<std::string, annotation *> annotation_map;

typedef std::vector<objc_protocol *> protocol_list;
typedef std::vector<objc_property *> property_list;
typedef std::vector<objc_class *> class_list;
typedef std::vector<annotation *> annotation_list;
