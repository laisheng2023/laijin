#include<stdio.h>
#include<math.h>
main ()
{
	int a[10][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int time=0;
	int number=0;
	int stop[11][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
	int now,d=1;   /*now��ʾ���ݵ�λ�ã�d��ʾ�˿���������*/
	int b;
	printf("������ÿ���˵ĵȴ�¥��(ֱ���������ֹ)="); 
	for (b=0;b<10;b++)   /*����ÿ�������ǲ㰴�µ���*/ 
	{
		int A;
		scanf("%d",&A);
		if (A==0)
		{
			break;
		}
		a[b][1]=1;
		a[b][0]=A;/*��ÿ��������¥���������*/ 
	}
	printf("����¥��  ʱ��  ����\n");
	printf("��������ݵĳ�ʼλ��=");
	scanf("%d",&now) ;/*������ݵĳ�ʼ¥��*/ 
	printf("%3d%3d%3d\n",now,time,number);/*������ݵĳ�ʼ״̬*/ 
	while (1)
	{
		if (a[0][1]==0&&a[1][1]==0&&a[2][1]==0&&a[3][1]==0&&a[4][1]==0&&a[5][1]==0&&a[6][1]==0&&a[7][1]==0&&a[8][1]==0&&a[9][1]==0)
		{
			break;/*����Ƿ������˵ĵȴ�¥���Ѵ���stop�У��������˳�ѭ��*/ 
		}
	    if (d==1)
	    {
	    	int i;
		    for (i=0;i<10;i++)
		    {
				if (d*a[i][0]>=d*now&&a[i][1]==1)
	            {
		            stop[a[i][0]][0]=1;/*�����������˵ĵȴ�¥�����stop������*/
		            a[i][1]=0;
	            } 
			}
			int h;
			for (h=1;h<11;h++)
			{ 
			    if (stop[h][0]!=0)
			    {
			    	time+=abs(now-h);/*������ݵ���˿ͽ���������¥������ʱ��*/ 
			    	number+=stop[h][0];/*������ݵ���ò��ǵ����ڵ�����*/
			    	now=h;/*��ǵ��ݴ˿̵�¥��*/
			    	printf("%3d%3d%3d\n",h,time,number);
			    	int B;
			    	printf("����������¥��=");
	                scanf ("%d",&B);/*����ó˿�����¥�㲢��������Ϣ������˿�����¥��*/ 
	                stop[B][1]-=1;
	                stop[h][0]=0;/*��Ǹó˿��Ѿ��������*/
	                
				}
			    if(stop[h][1]!=0)
				{
				   time+=abs(now-h);/*������ݵ���ó˿��߳����ݵ�¥������ʱ��*/
			       number+=stop[h][1];/*������ݵ���ó˿��߳����ݵ�¥��ʱ������*/ 
			       stop[h][1]=0;/*����ó˿�ȥ����¥�㲢��Ǹó˿��Ѿ�������*/
			       printf("%3d%3d%3d\n",h,time,number);/*��������Ϣ*/ 
			       now=h;/*��ǵ��ݴ˿̵�¥��*/
				}
	        }
	    }
	    else
	    {
	    	int i;
		    for (i=9;i>=0;i--)
		    {
				if (d*a[i][0]>=d*now&&a[i][1]==1)
	            {
		            stop[a[i][0]][0]=1;    /*�����������˵���Ϣ����stop������*/
		            a[i][1]=0;
	            } 
			}
			for (i=10;i>0;i--)
			{ 
			    if (stop[i][0]!=0)
			    {
			    	time+=abs(now-i);
			    	number+=stop[i][0];
			    	now=i;
			    	printf("%3d%3d%3d\n",i,time,number);
			    	int B;
	                printf("����������¥��=");
	                scanf("%d",&B);
	                stop[B][1]-=1;
	                stop[i][0]=0;
	                
				}
				if(stop[i][1]!=0)
				{
				    time+=abs(now-i);
			    	number+=stop[i][1];
			    	stop[i][1]=0;
			    	printf("%3d%3d%3d\n",i,time,number);
			    	now=i;
				}
			    
	        }/*����һ�γ�������*/ 
	    } 
		d=-d;	
    }
    int c;
	for (c=1;c<=10;c++) 
	{
		if (stop[c][1]!=0)
		{
			time+=abs(now-c);
			number+=stop[c][1];
			printf("%3d%3d%3d\n",c,time,number);
		}
	}
}
