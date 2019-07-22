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

//��ӡ�������
void print()
{
	int i;
	printf("\n----------------------------------------------"); 
	printf("\n����ֵΪ��%d\n",maxValue);
	printf("����ѡ��Ϊ��");
	for(i=1;i<=n;i++)
		printf("%d ",bestSelect[i]);
	printf("\n");
}
 
void main()
{
	int i,j,max[100];
	printf("��������Ʒ��Ŀ��\n");
	scanf("%d",&n) ;
	printf("��������Ʒ������Ŀ��\n");
	scanf("%d",&m) ;
	for(i=0;i<n;i++)
	{
		printf("\n�������%d����Ʒ�ļ�ֵ��",i+1);
		scanf("%d",&value[i]);
	}
	printf("\n��ֱ�����%d����Ʒ������\n",n);
	for(i=0;i<m;i++)
	{
		printf("������%d�������ĵ�%d�����ԣ�\n",n,i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&wp[j].trait[i]);
		} 
	} 
	printf("������%d�����Ե����ޣ�\n",m); 
	for(i=0;i<m;i++)
	{
		printf("\n�������%d�����Ե����ޣ�",i+1);
		scanf("%d",&max[i]);
	}

	//---------------���ݷ�ʵ������ѡ��---------------
	init();
	DFS(0,max,0);
	print();
}
