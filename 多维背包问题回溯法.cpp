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

//�����㷨ʵ�ֹ��� 
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

//��ӡ�������
void print()
{
	int i,sum=0;
	printf("\n----------------------------------------------"); 
	printf("\n����ֵΪ��%d\n",maxValue);
	printf("����ѡ��Ϊ��\n");
	for(i=1;i<=n;i++){
			if(bestSelect[i]==1) {
				sum+=value[i];
				printf("��Ʒ%d -->%d\n",i,value[i]);
			}
	}
	printf("�ܼ�ֵ ��%d\n",sum);
}
 
int main()
{
	int i,j,max[100];
	printf("��������Ʒ��Ŀ��\n");
	scanf("%d",&n) ;
	printf("��������Ʒ������Ŀ��\n");
	scanf("%d",&m) ;
	printf("������%d����Ʒ�ļ�ֵ��\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&value[i]);
	}
	printf("��ֱ�����%d����Ʒ��%d����\n",n,m);
	for(i=1;i<=m;i++)
	{
		printf("������%d����Ʒ�ĵ�%d�����ԣ�\n",n,i);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&wp[j].trait[i]);
		} 
	} 
	printf("������%d�����Ժ͵����ޣ�\n",m); 
	for(i=1;i<=m;i++)
	{
		scanf("%d",&max[i]);
	}

	//---------------���ݷ�ʵ������ѡ��---------------
	init();
	DFS(0,max,0);
	print();
}