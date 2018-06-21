## DeBUG时候的小问题

all数组虽然是local变量，但是，CB中默认debug时候无法正常显示。

需要自己在监视器watches里指定一次 all。

不过，此时，all[0]会以 elementtype形式存储。其余1，2.。则正常。

# 解题思路

使用自定义结构体为基础数据单元。 用变长数组all存储所有输入。

结构体stu 包括，string类的id， C,  M，E, A分别代表编程， 数学， 英语， 均分的值，前三项由读入得到，最终一项由前三项得到。

rC表示Rank Of C Language. 

rM, rE, rA同理。

读入完成后， 完成四次排序。 排序标准依次为C, M, E ,A。 每次排完序后，对all进行排序，得到rC, rM, rE, rA。 注意一下， 相同排名的解决办法，详见代码。

四次排序完成后， 按照A, C, M, E的优先级输出。

关于找到有没有对应的id， origin.cpp有我实现的其他方法。 main.cpp简单的遍历的一遍。 