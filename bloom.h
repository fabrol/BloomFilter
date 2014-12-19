//
//  hashes.cpp
//  BloomFilter
//
//  Created by Farhan Abrol on 12/18/14.
//  Copyright (c) 2014 Farhan Abrol. All rights reserved.
//

#include "hashes.h"
#include <string.h>
#include "utils.h"

template <typename KeyType, typename ValueType>
struct BloomFilter {

    BloomFilter (unsigned arr_sz_, unsigned num_hashes_);
    ValueType get (const KeyType & in_key, bool * found);
    void insert (const KeyType & in_key, const ValueType & in_val);
    void remove (const KeyType & in_key, const ValueType & in_val);

private:
    unsigned        arr_sz;
    unsigned        num_hashes;
    
    // Storage
    KeyType   *     keys;
    ValueType *     vals;
    unsigned  *     counts;
        
    // Hash values
    std::vector<uint32_t>       hash_indices;
    Hash_Container<KeyType>     hashes;
};



template <typename KeyType, typename ValueType>
BloomFilter<KeyType, ValueType>::BloomFilter (unsigned arr_sz_, unsigned num_hashes_)
: arr_sz(arr_sz_)
, num_hashes(num_hashes_)
{
    keys = new KeyType[arr_sz];
    vals = new ValueType[arr_sz];
    counts = new unsigned[arr_sz];
    hash_indices.resize(num_hashes);

}

template <typename KeyType, typename ValueType>
void BloomFilter<KeyType, ValueType>::insert (const KeyType & in_key, const ValueType & in_val)
{
    hashes.calculate_hashes(in_key, hash_indices);
    
    for (unsigned i = 0; i < num_hashes; ++i) {
        unsigned cur_idx = hash_indices[i] % arr_sz;
        
        counts[cur_idx] += 1;
        vals[cur_idx] ^= in_val;
        keys[cur_idx] ^= in_key;
    }
}

template <typename KeyType, typename ValueType>
ValueType BloomFilter<KeyType, ValueType>::get (const KeyType & in_key, bool * not_found)
{
    hashes.calculate_hashes(in_key, hash_indices);
    
    for (unsigned i = 0; i < num_hashes; ++i) {
        unsigned cur_idx = hash_indices[i] % arr_sz;
        if (!counts[cur_idx]) return NULL;
        
        if (counts[cur_idx] == 1) {
            if (keys[cur_idx] == in_key) {
                return vals[cur_idx];
            } else {
                return NULL;
            }
        }
    }
    
    // Cannot make a decision about this key
    *not_found = true;
    return NULL;
}

template <typename KeyType, typename ValueType>
void BloomFilter<KeyType, ValueType>::remove (const KeyType & in_key, const ValueType & in_val)
{
    for (unsigned i = 0; i < num_hashes; ++i) {
        unsigned cur_idx = hash_indices[i] % arr_sz;
        
        counts[cur_idx] -= 1;
        vals[cur_idx] ^= in_val;
        keys[cur_idx] ^= in_key;
        
    }
}
