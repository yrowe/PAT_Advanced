## DeBUG时候的小问题

all数组虽然是local变量，但是，CB中默认debug时候无法正常显示。

需要自己在监视器watches里指定一次 all。

不过，此时，all[0]会以 elementtype形式存储。其余1，2.。则正常。