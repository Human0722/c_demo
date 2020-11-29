<!--
 * @Author: your name
 * @Date: 2020-11-23 21:35:48
-->
```shell  
gcc -c -static add.c add.o  
gcc -c -static sub.c sub.o  
```


```shell 
ar -r libcal.a add.o sub.o  
```

```shell 
gcc -c main.c -o main.o  
gcc main.o libcal.a -o app
```

