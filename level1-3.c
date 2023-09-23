#include<stdio.h>
#include<math.h>
main ()
{
	int a[10][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int time=0;
	int number=0;
	int stop[11][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
	int now,d=1;   /*now表示电梯的位置，d表示此刻向上运行*/
	int b;
	printf("请输入每个人的等待楼层(直到输入零截止)="); 
	for (b=0;b<10;b++)   /*输入每个人在那层按下电梯*/ 
	{
		int A;
		scanf("%d",&A);
		if (A==0)
		{
			break;
		}
		a[b][1]=1;
		a[b][0]=A;/*将每个人所在楼层存入数组*/ 
	}
	printf("电梯楼层  时间  人数\n");
	printf("请输入电梯的初始位置=");
	scanf("%d",&now) ;/*输入电梯的初始楼层*/ 
	printf("%3d%3d%3d\n",now,time,number);/*输出电梯的初始状态*/ 
	while (1)
	{
		if (a[0][1]==0&&a[1][1]==0&&a[2][1]==0&&a[3][1]==0&&a[4][1]==0&&a[5][1]==0&&a[6][1]==0&&a[7][1]==0&&a[8][1]==0&&a[9][1]==0)
		{
			break;/*检查是否所有人的等待楼层已存入stop中，若是则退出循环*/ 
		}
	    if (d==1)
	    {
	    	int i;
		    for (i=0;i<10;i++)
		    {
				if (d*a[i][0]>=d*now&&a[i][1]==1)
	            {
		            stop[a[i][0]][0]=1;/*将满足条件人的等待楼层存入stop数组中*/
		            a[i][1]=0;
	            } 
			}
			int h;
			for (h=1;h<11;h++)
			{ 
			    if (stop[h][0]!=0)
			    {
			    	time+=abs(now-h);/*计算电梯到达乘客进电梯所在楼层所需时间*/ 
			    	number+=stop[h][0];/*计算电梯到达该层是电梯内的人数*/
			    	now=h;/*标记电梯此刻的楼层*/
			    	printf("%3d%3d%3d\n",h,time,number);
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
			       printf("%3d%3d%3d\n",h,time,number);/*输出相关信息*/ 
			       now=h;/*标记电梯此刻的楼层*/
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
		            stop[a[i][0]][0]=1;    /*将满足条件人的信息存入stop数组中*/
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
			    	printf("%3d%3d%3d\n",i,time,number);
			    	now=i;
				}
			    
	        }/*与上一段程序相似*/ 
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
