#include<stdio.h> 
#include<math.h>
main() 
{
	int A,B,C;     /*��A����һ�˵ȴ����ݵ���B�㣬��ʱ������C��*/ 
	int time=0;    /*��������ʱ��*/ 
	int n=0;       /*�����������*/ 
	scanf("%d%d%d",&A,&B,&C);
	printf("%3d%3d%3d\n",C,time,n);/*��ʾ�ڵ�C�㣬��������ʱ���Լ������������*/ 
	time=abs(C-A);
	n=1;
	printf("%3d%3d%3d\n",A,time,n);/*��������Ϣ*/ 
	time+=abs(A-B);
	n=0;
	printf("%3d%3d%3d\n",B,time,n);/*��������Ϣ*/
	
}
