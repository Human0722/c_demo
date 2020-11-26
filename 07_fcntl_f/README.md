<!--
 * @Author: Human0722
 * @Date: 2020-11-26 11:02:37
 * @FilePath: /c_demo/07_fcntl_f/README.md
-->
> 文件表指针
```c
struct file {
    unsigned int f_mode;
    unsigned int f_flags;
    unsigned short f_count;
    unsigned m_inode *f_inode;
    off_t f_pos;
}
```
> fcntl() 可以直接修改  ```f_flags``` 的值， 而不用 reopen 文件。  

```c
int fnctl(int fd, int cmd=F_GETFL);
int fnctl(int fd, int cmd=F_SETFL, int arg);
```
> 如何处理返回值  
```c
/* check value */
if(flags & O_RDONLY)
/* add value */
flags | O_RDONLY
```


