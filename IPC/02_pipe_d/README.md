<!--
 * @Author: Human0722 
 * @Date: 2020-12-16 21:52:04
 * @LastEditTime: 2020-12-16 21:59:33
 * @FilePath: /c_demo/IPC/02_pipe_d/README.md
-->

Main:   
1. make a pipe  
2. fork a process  
3. child process run child(), and child exit inside itself  
4. parent close read handler  
5. parent read from STDIN  
6. parent write data to pipe  
7. if word start with q, close write handler then quit  


Child: 
1. close write handler  
2. read from pipe  
3. if word start with q, close read handler then quit 
