#include<stdio.h>
int t;
int activity_selector();
void quicksort(int left,int right);
//定义一个结构体，把每个活动的结束时间和开始时间存入
struct note
{
	int start;
	int end;
}q[10000];
int main()
{
	int res,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&q[i].start,&q[i].end);
	}
	quicksort(1,t);
	res=activity_selector();
	printf("%d\n",res);
}
void quicksort(int left,int right)//快速排序法
{
	int temp=q[left].end;
	int temp1=q[left].start;
	int i,j,t,f;
	i=left;
	j=right;
	if(right<left)
	{
		return;
	}
	while(i!=j)
	{
		while(i<j && q[j].end>=temp)
		{
			j--;
		}
		while(i<j && q[i].end<=temp)
		{
			i++;
		}
		if(i<j)
		{
		t=q[i].end;
		q[i].end=q[j].end;
		q[j].end=t;
		f=q[i].start;
		q[i].start=q[j].start;
		q[j].start=f;
		}
	}
	q[left].end=q[i].end;
	q[i].end=temp;
	q[left].start=q[i].start;
	q[i].start=temp1;
	quicksort(left,i-1);
	quicksort(i+1,right);
}
int activity_selector()//用来算出可以安排的活动数量
{
	int num=1,i=1;
	int j;
	for(j=2;j<=t;j++)
	{
		if(q[j].start>q[i].end)
		{
			i=j;
			num++;
		}
	}
	return num;
}

