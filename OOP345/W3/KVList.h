// Workshop 3 - Class Templates
// KVList.h
// Yue Chen
// 2018.06.06

#pragma once

template <typename K, typename V, int N>
class KVList {
    K keyArray[N];
    V valueArray[N];
    typedef unsigned size_t;
public:
    KVList() {}
    size_t size() const {
        size_t count = 0;
        for (size_t i = 0; i < N && keyArray[i] != ""; i++) {
            count++;
        }
        return count;
    }
    const K& key(int i) const {
        if (i < size())
            return keyArray[i];
        else
            return keyArray[0];
    }
    const V& value(int i) const {
        if (i < size())
            return valueArray[i];
        else
            return valueArray[0];
    }
    KVList& add(const K& k, const V& v) {
        size_t s = size();
        if (s < N) {
            keyArray[s] = k;
            valueArray[s] = v;
        }
        return *this;
    }
    int find(const K& k) const {
       
       
        for (int i = 0; i < size() ; i++) {
            
            if ( keyArray[i] == k ) return i;
        }
        return 0;
    }
    KVList& replace(int i, const K& k, const V& v) {
        keyArray[i] = k;
        valueArray[i] = v;
        return *this;
    }
    ~KVList() {};
};