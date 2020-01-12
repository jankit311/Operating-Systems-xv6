#include "types.h"
#include "param.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "merafile.h"

int checkequal(char * a, char * b){
   while(*a != '\0' && *b != '\0'){
     if(*a != *b)
        return 0;
     a++;
     b++;
   }
   if(!(*a == '\0' && *b == '\0')) return 0;
   return 1;
}

void sort(struct process_info pp[],int count){
    int i,j;
    for(i=0;i<count;i++)
       for(j=0;j<count-i-1;j++)
          if(pp[j+1].sz > pp[i].sz){
             struct process_info copy=pp[j+1];
             pp[j+1]=pp[j];
             pp[j]=copy;
    }
}

int main(int argc, char *argv[])
{

 struct process_info pp[NPROC];
 int count=0;
 cps(pp,&count);
 
 int i=0;
 
 if(argc == 2){
   if(checkequal(argv[1],"-n")){
      for(i=0;i<count;i++)
        printf(1,"%s\n",pp[i].name);
   }
   else if(checkequal(argv[1],"-l")){
      for(i=0;i<count;i++)
        printf(1,"name = %s     size = %d    pid = %d   ppid = %d\n ",pp[i].name,pp[i].sz,pp[i].pid,pp[i].ppid);
   }
   else if(checkequal(argv[1],"-m")){
      sort(pp,count);
      for(i=0;i<count;i++)
        printf(1,"name = %s     size = %d    pid = %d   ppid = %d\n ",pp[i].name,pp[i].sz,pp[i].pid,pp[i].ppid);
   }
   else if(checkequal(argv[1],"-sh")){
      for(i=0;i<count;i++)
        if(checkequal(pp[i].state,"SLEEPING"))
          printf(1,"name = %s     size = %d    pid = %d   ppid = %d state = %s\n",pp[i].name,pp[i].sz,pp[i].pid,pp[i].ppid,pp[i].state);
   }
 }
 else if(argc == 3){
   if(checkequal(argv[1],"-d")){
      for(i=0;i<count;i++){
        if(checkequal(pp[i].name,argv[2]))
          printf(1,"process id of process with name %s is %d\n",pp[i].name,pp[i].pid);
      }
   }
 }
 
 exit();
}
