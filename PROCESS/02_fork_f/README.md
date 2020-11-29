if parent process do not run sleep(),it will finish before child process. the return value from child process will be 1 which is the pid of init process. 

if you run code like this:  
```shell
> gcc -o fork fork.c
> ./fork > tmp.txt
```  

you will find content of tmp.txt like this: 

```
I'm father process!
Before fork~
I'm child process, pid is 19380, my father's pid is 19379
Before fork~
I'm father process, pid is 19379, my child's pid is 19380
``` 
it output double ```Before fork```, this is because function printf will output content to terminal directly,but if output to file , it will not write content to file util meet '\n';