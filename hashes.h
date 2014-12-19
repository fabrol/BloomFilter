//
//  hashes.cpp
//  BloomFilter
//
//  Created by Farhan Abrol on 12/18/14.
//  Copyright (c) 2014 Farhan Abrol. All rights reserved.
//

#include "Hash_Choices.h"
#include <vector>
#include <iostream>

using namespace std;

// A container of hashing algorithms.
template <typename KeyType>
struct Hash_Container {

    std::vector<hasher::HashInfo*> hash_algs;

    // Defaults to using two hashing algs
    Hash_Container(const char * hash1= "Murmur3A", const char * hash2 = "FNV");
    void calculate_hashes (const KeyType & in_key, std::vector<uint32_t> & hash_indices);
};


template <typename KeyType>
Hash_Container<KeyType>::Hash_Container(const char * hash1, const char * hash2)
{
    if (!hasher::findHash(hash1) || !hasher::findHash(hash2)) {
        cout << "Invalid hashes requested";
    } else {
        hash_algs.push_back(hasher::findHash(hash1));
        hash_algs.push_back(hasher::findHash(hash2));
    }
    
}

template <typename KeyType>
void Hash_Container<KeyType>::calculate_hashes(const KeyType & in_key, std::vector<uint32_t> & hash_indices)
{
    assert(hash_indices.size() == 2);
    for (unsigned i = 0; i < hash_indices.size(); ++i) {
        hash_algs[i]->hash(&in_key, sizeof(in_key), 0, &hash_indices[i]);
    }
}
