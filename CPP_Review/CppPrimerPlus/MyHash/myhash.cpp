//
// Created by alex on 11/14/18.
//

#include "myhash.h"

int HashTable::InitHashTable() {
    int i;
    count = 0;
    size = 0;   // 初始化容量为HashSize[0] = 11
    HashLength = HashSize[0];
    elem = new ElemType[HashLength];
    if (!elem)
    {
        cout << "memory error!" << endl;
        exit(0);
    }
    for (i = 0; i < HashLength; i++)
        elem[i].key = NULLKEY;
    return 1;
}

void HashTable::DestroyHashTable() {
    delete[]elem;
    elem = nullptr;
    count = 0;
    size = 0;
}

unsigned HashTable::Hash(KeyType k) {
    return static_cast<unsigned int>(k % HashLength);
}

void HashTable::Collision(int &p, int d) {

}

bool HashTable::SearchHash(KeyType k, int &p) {
    return false;
}

int HashTable::InsertHash(ElemType e) {
    return 0;
}

void HashTable::ReCreateHashTable() {

}

void HashTable::TraverseHashTable() {

}

void HashTable::GetData(int p) {

}

