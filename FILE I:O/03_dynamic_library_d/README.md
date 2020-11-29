<!--
 * @Author: your name
 * @Date: 2020-11-23 21:46:12
-->
```shell
> cd src
> gcc -fpic -shared sub.c add.c -o ../lib/libcal.so
```  

```shell
> gcc -c main.c
> gcc main.o ../lib/libcal.so -o ../bin/app
> 或者 gcc main.o -L../lib -lcal -o ../bin/app
```  

<font color="red">Use -L need to set LD_LIBRARY_PATH:</font>
```shell
> export LD_LIBRARY_PATH=$PROJ/lib
```