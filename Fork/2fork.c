/*

The fork system call creates a new process. The new process created by fork() is a copy of the current process except for the returned value. ::::(copy)
The exec() system call replaces the current process with a new program.:::: (new ,not a copy)

*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  

int main() 
{ 
    int a=0;
    if (fork() == 0) 
    { 
    a = a+5; 
    printf("%d", a); 
    } 
else 
{ 
    a = a-5; 
    printf("%d", a); 
} 
    return 0; 
} 

Let p be the values printed by the parent process, and c be the values printed by the child process. 
then p+10=c;
