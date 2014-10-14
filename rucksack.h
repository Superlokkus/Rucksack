//
//  rucksack.h
//  Rucksack
//
//  Created by Markus Klemm on 01.10.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#ifndef Rucksack_rucksack_h
#define Rucksack_rucksack_h

#include <string>
#include <vector>
#include <iostream>

namespace rucksack
{
    struct Item
    {
        unsigned size;
        std::string name;
        
        Item (const unsigned s, const std::string &n) : size(s),name(n) {}
    };
    
    class Rucksack
    {
    public:
        unsigned size() const noexcept {return psize;}
        void setsize(const unsigned s) noexcept {psize = s;}
        
        void addItem (const Item &i) {items.push_back(i);}
        void addItem (Item &&i) {items.push_back(i);}
        
        void showAssigendItems (void) const
        {
            //std::ostream s;
            std::cout << "Name Size" << std::endl;
            for (const auto &i : items)
            {
                std::cout << i.name << i.size << std::endl;
            }
        }
        
        void optimize()
        {
            std::vector<std::vector<std::pair<size_type, std::vector<Item*>>>> matrix; //(k,s) matrix
            
            std::pair<size_type, std::vector<Item*>> empty = std::make_pair(0,std::vector<Item*>({nullptr}));
            
            for (auto k = 0; k <= items.size(); k++) {
                std::vector<std::pair<size_type, std::vector<Item*>>> row;
                if (k == 0)
                {
                    row.emplace_back(empty);
                }
                for (decltype(Rucksack::size()) s = 0; s <= this->size(); s++) {
                    if (s < matrix[k-1].at(s).first) {
                        row.emplace_back((matrix[k-1]).at(s));
                    }
                    else
                    {
                        std::pair<size_type, std::vector<Item*>> cell;
                        if (matrix[k-1].at(s).first < matrix[k-1].at(s - items[k].size ).first + items[k].size)
                        {
                            //Pack the k-th item
                            cell.second = matrix[k-1].at(s - items[k].size ).second;
                            cell.second.emplace_back(&items[k]);
                            cell.first = matrix[k-1].at(s - items[k].size ).first + items[k].size;
                        }
                        else
                        {
                            cell.second = matrix[k-1].at(s).second;
                            cell.first = matrix[k-1].at(s).first;
                        }
                        row.emplace_back(cell);
                        
                    }
                }
                matrix.emplace_back(std::move(row));
            }
        }
        
        Rucksack(const unsigned s, std::vector<Item> && i)
        : psize(s), items(std::move(i)) {optimize();}
        Rucksack(const unsigned s) : psize(s) {}
        
    private:
        using size_type = unsigned;
        
        size_type psize;
        std::vector<Item> items;
    };
}

#endif
