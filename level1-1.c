#include<stdio.h> 
#include<math.h>
main() 
{
	int A,B,C;     /*第A层有一人等待电梯到第B层，此时电梯在C层*/ 
	int time=0;    /*电梯运行时间*/ 
	int n=0;       /*电梯里的人数*/ 
	scanf("%d%d%d",&A,&B,&C);
	printf("%3d%3d%3d\n",C,time,n);/*表示在第C层，电梯运行时间以及电梯里的人数*/ 
	time=abs(C-A);
	n=1;
	printf("%3d%3d%3d\n",A,time,n);/*输出相关信息*/ 
	time+=abs(A-B);
	n=0;
	printf("%3d%3d%3d\n",B,time,n);/*输出相关信息*/
	
}
