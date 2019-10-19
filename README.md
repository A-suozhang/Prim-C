# Prim-C
* Dirty Implemention Of Prim Algo In C++
* 北航通信网络原理课程作业

# 使用姿势
* 没有任何优化，直接一个大循环
* 维护了一个已经在树里的Vertex的数组
* 对其中的Vertex所链接的所有边（除去可能会成环的（也就是又和上面集合中的Vertex相连））以及不是边的（因为严格来说adjacent matrix内部用0来表示没有链接上，会对取min带来麻烦）
* 把每一轮循环找出来的最小边打印，并且将相连的Vertex加入集合
* 测试用的图
    * ![](https://github.com/A-suozhang/MyPicBed/raw/master/img/20191019161738.png)
* 结果如下
    * ![](https://github.com/A-suozhang/MyPicBed/raw/master/img/20191019161611.png)

