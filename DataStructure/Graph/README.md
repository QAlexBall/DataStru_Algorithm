### 图(Graph)
***
##### 抽象数据类型图的定义
```c
ADT Graph {
    数据对象V： V是具有相同特性的数据元素的集合，称为**顶点集**
    数据关系R： 
            R = {VR}
            VR = {<v, w> | v, w 属于V, 且p(v, w), <v, w>表示从v到w的弧，
                    谓词P(v, w)定义了弧<v, w>的意义或信息}
    基本操作P：
        CreateGraph(&G, V, VR);
            初始条件： V是图的顶点集，VR是图中弧的集合
            操作结果： 按V和VR的定义构造图G

} ADT Graph
```
***
在图中所有数据元素通常称作顶点(Vertext),V是顶点的有穷非空集合;
VR是两个顶点之间的关系集合。