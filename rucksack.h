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
#include <algorithm>

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
            using cell = std::pair<size_type, std::vector<Item*>>;
            
            std::vector<std::vector<cell>> matrix; //(k,s) matrix
            cell empty = std::make_pair(0,std::vector<Item*>({nullptr}));
            
            for (auto k = 0; k <= items.size(); k++)
            {
                std::vector<cell> row;
                for (decltype(Rucksack::size()) s = 0; s <= this->size(); s++)
                {
                    if (k == 0)
                    {
                        row.emplace_back(empty);
                    }
                    else if (s < items[k-1].size) {
                        row.emplace_back((matrix[k-1]).at(s));
                    }
                    else
                    {
                        cell cell;
                        if (matrix[k-1].at(s).first < matrix[k-1].at((s < items[k-1].size ) ? 0 : s - items[k-1].size ).first + items[k-1].size)
                        {
                            //Pack the k-th item
                            cell.second = matrix[k-1].at((s < items[k-1].size ) ? 0 : s - items[k-1].size).second;
                            cell.second.emplace_back(&items[k-1]);
                            cell.first = matrix[k-1].at((s < items[k-1].size ) ? 0 : s - items[k-1].size).first + items[k-1].size;
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
#ifndef _NDEBUG
            for (auto k : matrix)
            {
                for (auto s : k)
                {
                    std::cout << s.first << " ";
                }
                std::cout << std::endl;
            }
#endif
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
