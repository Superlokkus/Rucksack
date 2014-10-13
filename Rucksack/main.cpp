//
//  main.cpp
//  Rucksack
//
//  Created by Markus Klemm on 01.10.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <iostream>
#include <vector>
#include "rucksack.h"


int main(int argc, const char * argv[]) {
    
    std::vector<rucksack::Item> items = {
        {6,std::string("Kugel")},{2,std::string("Stift")},{1,std::string("Klammer")},{7,std::string("Laptop")}
    };

    rucksack::Rucksack R(10,std::move(items));
    
    
    
    return 0;
}
