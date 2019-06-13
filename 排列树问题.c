#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 100000

typedef struct Circle{
	float min,//����ֵ 
	      *x,//��ǰԲ����Բ�ĺ����� 
	      *r;//��ǰԲ����
	int n; 
}Circle;
Circle C;
float *a,//�������Ž�
	  *b;
int	  *rf;//��¼Բ��״̬ 
//int n=0;

float CirclePerm();//������СԲ���г��� 
float Center(int);//���㵱ǰԲ�ڵ�ǰԲ�����е�Բ�ĺ����� 
void Compute();//����Բ���г��� 
void Backtrack(int);//������ȱ���������

float CirclePerm(){
	C.x=(float *)malloc((C.n+1)*sizeof(float));
	Backtrack(1);
	return C.min;
}
float Center(int t){
	float temp=0,valuex;
	int i;
	for(i=1;i<t;i++){
		valuex=C.x[i]+2.0*sqrt(b[i]*b[t]);//���㵱ǰԲ�뵱ǰԲ����ÿ��Բ֮��ľ���(������Բ����),��Ϊsqrt����ֵ��double�͵����������и����� 
		if(valuex>temp) temp=valuex;
	}
	return temp;	
}
void Compute(){
	int i;
	float low=0,high=0,m=high-low;
//	n++;
	for(i=1;i<=C.n;i++){
		if(C.x[i]-b[i]<low)  low=C.x[i]-b[i];//������С��߽� 
		if(C.x[i]+b[i]>high) high=C.x[i]+b[i];//��������ұ߽� 
	}
/*	m=high-low;
    //���ÿ��Բ���м�����
	printf("\nԲ�У�\n");
	for(i=1;i<=C.n;i++){
		printf("%7.1f",b[i]);
	}
	printf("  ���ȣ�%8.2f\n",m); 
	*/
   	if(high-low<C.min){
		C.min=high-low;
		for(i=0;i<C.n;i++){//�������Ž�
			a[i]=b[i+1];
		}
	}
}
void Backtrack(int t){
	int j;
	float centerx;
	 if(t>C.n) Compute();
	 else 
	  for(j=1;j<=C.n;j++){
	  	 if(1==rf[j]) continue;
		 b[t]=C.r[j];
  		 centerx=Center(t);//���㵱ǰԲ�ĺ�����
  		 rf[j]=1;
		 if(centerx+b[t]+b[1]<C.min){
 			C.x[t]=centerx;
 			Backtrack(t+1);
		 }else{
			 /*printf("\nԲ���У�\n");//�����������Բ����
			 for(i=1;i<=t;i++){
				printf("%7.2f",C.r[i]);
			 }
			 printf("����");n++;*/
		 }
		rf[j]=0;
  	  }
}
main(){
	int i;
	float min;
	a=(float *)malloc(C.n*sizeof(float));
	b=(float *)malloc((C.n+1)*sizeof(float));//��¼ÿ�ε����� 
	rf=(int *)malloc((C.n+1)*sizeof(int));//����Ѿ�ʹ�õ�Բ 
	printf("����Բ�ĸ�����");
	scanf("%d",&C.n);
	C.r=(float *)malloc((C.n+1)*sizeof(float));//
	printf("��������Բ�İ뾶��\n");
	for(i=1;i<=C.n;i++){
		rf[i]=0;//��ʼ�����
		scanf("%f",&C.r[i]);
	}
	C.min=MIN;
	min=CirclePerm();
	printf("\n\n��С���ȣ�%f\n",min);

	
	printf("\n\n");
	//printf("��������%d\n",n);
	getchar();
	getchar();
	return 0;
} 
