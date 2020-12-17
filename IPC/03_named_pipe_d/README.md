<!--
 * @Author: Human0722
 * @Date: 2020-12-16 22:35:08
 * @LastEditTime: 2020-12-16 23:01:53
 * @FilePath: /c_demo/IPC/03_named_pipe_d/README.md
-->
Make a fifo file with command ``` mkfifo ```  

```shell
[root@localhost env]# mkfifo hello
[root@localhost env]# ll
prw-r--r--. 1 root root 0 12月 16 09:37 hello
```  

``` prw-r--r--```: p means pipe.

This demo read data from terminal then write data to pipe file with sender, receiver read data from pipe file.
