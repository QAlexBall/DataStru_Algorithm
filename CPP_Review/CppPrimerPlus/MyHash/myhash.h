//
// Created by alex on 11/14/18.
//

#ifndef MYHASH_H_
#define MYHASH_H_

#include <iostream>
using namespace std;

typedef int KeyType;    // 设关键字域为整形
const int NULLKEY=0;    // NULLKEY表示该位置无值
int c = 0;              // 用来统计冲突次数

struct ElemType // 数据元素类型
{
    KeyType key;
    int ord;
};

int HashSize[] = {11, 19, 29, 37, 47};  // hash表容量递增
int HashLength = 0;                     // hash表表长

class HashTable
{
private:
    ElemType *elem; // 数据元素数组, 动态申请
    int count;      // 当前数据元素个数
    int size;       // 决定hash表的容量为第几个, HashSize[size]为当前hash容量

public:
    int InitHashTable();
    void DestroyHashTable();
    unsigned Hash(KeyType k);
    void Collision(int &p, int d);
    bool SearchHash(KeyType k, int &p);
    int InsertHash(ElemType e);
    void ReCreateHashTable();
    void TraverseHashTable();
    void GetData(int p);
};

#endif //MYHASH_H_
