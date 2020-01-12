#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc,char* argv[])
{
	int n,i,pid;
	if(argc<=1)
	{
		//printf(1,"Enter the no of processes\n");
		//scanf("%d",&n);
		return 0;
	}
	else
	{
		n = atoi(argv[1]);
	}
	//printf("%d\n",n);
	pid = fork();
	for(i=0;i<n-1;i++)
	{
		if(pid==0)
		{
			pid = fork();
		}
	}
	sleep(1500);
	return 0;
}
