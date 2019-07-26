#include<stdio.h> 

int n,m,maxValue;
int bestSelect[100],select[100],value[100];
struct goods{
	int trait[100];	
};
struct goods wp [100];
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
		for(i=1;i<=m;i++)
		{
			if(currentTrait[i]<wp[level+1].trait[i])
				flag=0;
			 
		}
		if(flag)
		{
		
			for(i=1;i<=m;i++)
			{
				currentTrait[i]-=wp[level+1].trait[i];
			}
			current_value = current_value + value[level+1];
			select[level+1] = 1;
		
			DFS(level+1,currentTrait,current_value);
			 
			select[level+1] = 0;
			for(i=1;i<=m;i++)
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
	int i,sum=0;
	printf("\n----------------------------------------------"); 
	printf("\n最大价值为：%d\n",maxValue);
	printf("最优选择为：\n");
	for(i=1;i<=n;i++){
			if(bestSelect[i]==1) {
				sum+=value[i];
				printf("物品%d -->%d\n",i,value[i]);
			}
	}
	printf("总价值 ：%d\n",sum);
}
 
int main()
{
	int i,j,max[100];
	printf("请输入物品数目：\n");
	scanf("%d",&n) ;
	printf("请输入物品属性数目：\n");
	scanf("%d",&m) ;
	printf("请输入%d个物品的价值：\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&value[i]);
	}
	printf("请分别输入%d个物品的%d属性\n",n,m);
	for(i=1;i<=m;i++)
	{
		printf("请输入%d个物品的第%d个属性：\n",n,i);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&wp[j].trait[i]);
		} 
	} 
	printf("请输入%d个属性和的上限：\n",m); 
	for(i=1;i<=m;i++)
	{
		scanf("%d",&max[i]);
	}

	//---------------回溯法实现最优选择---------------
	init();
	DFS(0,max,0);
	print();
}