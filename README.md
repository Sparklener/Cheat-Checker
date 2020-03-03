# Cheat-Checker

对luogu的反作弊系统看不下去了

而且觉得本地上面的比赛也有很多的作弊者

于是就有了本项目

欢迎`star`和`contribute`

记录:

```
g++ -E filename.cpp > output.txt
g++ -S filename.cpp //生成filename.s的汇编文件
```

`#define`里面的内容会内联进调用的位置

编译信息是: `# 行号 文件名`

结论:

编译信息帮助其实不大，展开了`#define`而且有主体部分，但是分开比较麻烦

要是直接`hash`编译信息的话还不如直接`hash`源码

当前困难:

1. typedef & #define

```cpp
typedef long long ll;
#define ll long long
```

2. func & #define 

```cpp
#define lowbit(i) ((i) & (-i))
int lowbit(int i){return ((i) & (-i));}
```

目标:

1. 掐头去尾
2. 替换变量
3. 封装函数
4. 编译结果文件哈希
5. 大小写
6. 快读和快写处理
7. 数据范围
8. 数组开始的位置(0 / 1)
9. 实际运行速度比对(Increase Speed)
