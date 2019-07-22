#include<stdio.h> 

int n,m,maxValue;
int bestSelect[100],select[100],value[100];
struct goods{
	int trait[100];	 
};
struct goods wp [10];

void init()			
{
	int i;
	maxValue = 0;
	for(i=1;i<=n;i++)
		select[i] = 0;	 
}

//回溯算法实现过程 
void DFS(int level,int currentTrait[100],int current_value)
{
	int i=0;
	if(level>=n+1)	
	{
		if(current_value>maxValue)		
		{
			int i;
			maxValue = current_value;
			for(i=1;i<=n;i++)		
				bestSelect[i] = select[i];	 
		}
	}
	else
	{
		bool flag=1;
		for(i=0;i<m;i++)
		{
			if(currentTrait[i]<wp[level+1].trait[i])
				flag=0;
		
		}
		if(flag)
		{
			 
			for(i=0;i<m;i++)
			{
				currentTrait[i]-=wp[level+1].trait[i];
			}
			current_value = current_value + value[level+1];
			select[level+1] = 1;
			
			DFS(level+1,currentTrait,current_value);
		 
			select[level+1] = 0;
			for(i=0;i<m;i++)
			{
				currentTrait[i]+=wp[level+1].trait[i];
			}
			current_value = current_value - value[level+1];
		}
	
		DFS(level+1,currentTrait,current_value);
	}
}

//打印输出函数
void print()
{
	int i;
	printf("\n----------------------------------------------"); 
	printf("\n最大价值为：%d\n",maxValue);
	printf("最优选择为：");
	for(i=1;i<=n;i++)
		printf("%d ",bestSelect[i]);
	printf("\n");
}
 
void main()
{
	int i,j,max[100];
	printf("请输入物品数目：\n");
	scanf("%d",&n) ;
	printf("请输入物品属性数目：\n");
	scanf("%d",&m) ;
	for(i=0;i<n;i++)
	{
		printf("\n请输入第%d个物品的价值：",i+1);
		scanf("%d",&value[i]);
	}
	printf("\n请分别输入%d个物品的属性\n",n);
	for(i=0;i<m;i++)
	{
		printf("请输入%d个背包的第%d个属性：\n",n,i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&wp[j].trait[i]);
		} 
	} 
	printf("请输入%d个属性的上限：\n",m); 
	for(i=0;i<m;i++)
	{
		printf("\n请输入第%d个属性的上限：",i+1);
		scanf("%d",&max[i]);
	}

	//---------------回溯法实现最优选择---------------
	init();
	DFS(0,max,0);
	print();
}
