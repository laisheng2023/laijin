#include<stdio.h>
#include<math.h>
main ()
{
	int a[10][3]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};/*存储乘客的相关信息*/ 
	int time=0;
	int number=0;
	int stop[11][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; /*stop数组模拟电梯的运行*/ 
	int now,d=1;   /*now表示电梯的位置，d表示此刻向上运行*/
	int b;
	printf("请输入每个人的等待楼层="); 
	for (b=0;b<10;b++)   /*输入每个人在哪层按下电梯*/ 
	{
		int A;
		scanf("%d",&A); 
		if (A==0)
		{
			break;
		}
		a[b][2]=1;
		a[b][0]=A;/*将每个人所在楼层存入数组*/ 
	}
	int c; 
	printf("请输入每个人的延迟时间=");
	for (c=0;c<10;c++)   
	{
		int B;
		scanf("%d",&B); 
		if (B==0)
		{
			break;
		}
		a[c][1]=B;/*将每个人延迟时间存入数组*/ 
	}
	printf("电梯楼层  时间  人数\n");
	printf("请输入电梯的初始位置=");
	scanf("%d",&now) ;/*输入电梯的初始楼层*/ 
	printf("%4d%4d%4d\n",now,time,number);/*输出电梯的初始状态*/ 
	int time1=0;	
	while (1)
	{
		int t;
	    int min=100;
	    for (t=0;t<10;t++)
	    {
		    if(a[t][1]<=min&&(a[t][2]==1||a[t][0]!=0))
		    {
			    min=a[t][1];/*找出延迟时间最短的人*/ 
		    }
	    }
	    if (a[0][2]==0&&a[1][2]==0&&a[2][2]==0&&a[3][2]==0&&a[4][2]==0&&a[5][2]==0&&a[6][2]==0&&a[7][2]==0&&a[8][2]==0&&a[9][2]==0)
	    {
	    	min=0;
		}
	    int h;
	    for (h=0;h<10;h++)
	    {
		    if(a[h][2]!=0)
		    {
			    a[h][1]-=min;/*每位乘客减去相同的延迟时间使得有一位乘客延迟时间为零，即按下电梯键*/ 
		    }
	    }
	    time+=min;
	    time1+=min; 
		int s;
		for(s=0;s<=9;s++)
		{
			if(a[s][2]!=0&&a[s][1]-time+time1>=0)
			{
				a[s][1]-=(time-time1);
			}
			if(a[s][2]!=0&&a[s][1]-time+time1<0)
			{
				a[s][1]=0;/*电梯运行一次后未进入电梯的乘客剩余延迟时间*/ 
			}
		}
		time1=time;
		if (a[0][2]==0&&a[1][2]==0&&a[2][2]==0&&a[3][2]==0&&a[4][2]==0&&a[5][2]==0&&a[6][2]==0&&a[7][2]==0&&a[8][2]==0&&a[9][2]==0)
		{
			break;/*检查是否所有人的等待楼层已存入stop中，若是则退出循环*/ 
		}
	    if (d==1)
	    {
	    	int p;
	    	for (p=0;p<=9;p++)
			{
				if(abs(a[p][0]-now)>=a[p][1]&&a[p][2]==1&&d*a[p][0]>=d*now)
				{
					stop[a[p][0]][0]=1;
					a[p][2]=0;
				}
			}       /*将乘客的信息存入stop*/ 
			int h;
			for (h=1;h<11;h++)
			{ 
			    if (stop[h][0]!=0)
			    {
			    	time+=abs(now-h);/*计算电梯到达乘客进电梯所在楼层所需时间*/ 
			    	number+=stop[h][0];/*计算电梯到达该层是电梯内的人数*/
			    	now=h;/*标记电梯此刻的楼层*/
			    	printf("%4d%4d%4d\n",h,time,number);
			    	int B;
			    	printf("请输入所到楼层=");
	                scanf ("%d",&B);/*到达该乘客所在楼层并输出相关信息，输入乘客所到楼层*/ 
	                stop[B][1]-=1;
	                stop[h][0]=0;/*标记该乘客已经进入电梯*/
	                
				}
			    if(stop[h][1]!=0)
				{
				   time+=abs(now-h);/*计算电梯到达该乘客走出电梯的楼层所需时间*/
			       number+=stop[h][1];/*计算电梯到达该乘客走出电梯的楼层时的人数*/ 
			       stop[h][1]=0;/*到达该乘客去往的楼层并标记该乘客已经出电梯*/
			       printf("%4d%4d%4d\n",h,time,number);/*输出相关信息*/ 
			       now=h;/*标记电梯此刻的楼层*/
				}
	        }
	    }
	    else
	    {
	    	int p;
	    	for (p=0;p<=9;p++)
			{
				if(abs(a[p][0]-now)>=a[p][1]&&a[p][2]==1&&d*a[p][0]>=d*now)
				{
					stop[a[p][0]][0]=1;
					a[p][2]=0;
				}
			}/*将乘客的信息存入stop*/ 
			int i;
			for (i=10;i>0;i--)
			{ 
			    if (stop[i][0]!=0)
			    {
			    	time+=abs(now-i);
			    	number+=stop[i][0];
			    	now=i;
			    	printf("%4d%4d%4d\n",i,time,number);
			    	int B;
	                printf("请输入所到楼层=");
	                scanf("%d",&B);
	                stop[B][1]-=1;
	                stop[i][0]=0;
	                
				}
				if(stop[i][1]!=0)
				{
				    time+=abs(now-i);
			    	number+=stop[i][1];
			    	stop[i][1]=0;
			    	printf("%4d%4d%4d\n",i,time,number);
			    	now=i;
				}
			    
	        }/*与上一段程序相似*/ 
	    } 
		d=-d;	
    }
    int q;
	for (q=1;q<=10;q++) 
	{
		if (stop[q][1]!=0)
		{
			time+=abs(now-q);
			number+=stop[q][1];
			printf("%4d%4d%4d\n",q,time,number);/*输出最后一位乘客出电梯时的数据*/ 
		}
	}
}
