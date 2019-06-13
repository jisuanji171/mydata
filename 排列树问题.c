#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN 100000

typedef struct Circle{
	float min,//最优值 
	      *x,//当前圆排列圆心横坐标 
	      *r;//当前圆排列
	int n; 
}Circle;
Circle C;
float *a,//保存最优解
	  *b;
int	  *rf;//记录圆的状态 
//int n=0;

float CirclePerm();//返回最小圆排列长度 
float Center(int);//计算当前圆在当前圆排列中的圆心横坐标 
void Compute();//计算圆排列长度 
void Backtrack(int);//深度优先遍历排列树

float CirclePerm(){
	C.x=(float *)malloc((C.n+1)*sizeof(float));
	Backtrack(1);
	return C.min;
}
float Center(int t){
	float temp=0,valuex;
	int i;
	for(i=1;i<t;i++){
		valuex=C.x[i]+2.0*sqrt(b[i]*b[t]);//计算当前圆与当前圆列中每个圆之间的距离(假设两圆相切),因为sqrt返回值是double型的所以这里有个警告 
		if(valuex>temp) temp=valuex;
	}
	return temp;	
}
void Compute(){
	int i;
	float low=0,high=0,m=high-low;
//	n++;
	for(i=1;i<=C.n;i++){
		if(C.x[i]-b[i]<low)  low=C.x[i]-b[i];//计算最小左边界 
		if(C.x[i]+b[i]>high) high=C.x[i]+b[i];//计算最大右边界 
	}
/*	m=high-low;
    //输出每次圆排列及长度
	printf("\n圆列：\n");
	for(i=1;i<=C.n;i++){
		printf("%7.1f",b[i]);
	}
	printf("  长度：%8.2f\n",m); 
	*/
   	if(high-low<C.min){
		C.min=high-low;
		for(i=0;i<C.n;i++){//保存最优解
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
  		 centerx=Center(t);//计算当前圆心横坐标
  		 rf[j]=1;
		 if(centerx+b[t]+b[1]<C.min){
 			C.x[t]=centerx;
 			Backtrack(t+1);
		 }else{
			 /*printf("\n圆排列：\n");//输出被剪掉的圆排列
			 for(i=1;i<=t;i++){
				printf("%7.2f",C.r[i]);
			 }
			 printf("被剪");n++;*/
		 }
		rf[j]=0;
  	  }
}
main(){
	int i;
	float min;
	a=(float *)malloc(C.n*sizeof(float));
	b=(float *)malloc((C.n+1)*sizeof(float));//记录每次的排列 
	rf=(int *)malloc((C.n+1)*sizeof(int));//标记已经使用的圆 
	printf("输入圆的个数：");
	scanf("%d",&C.n);
	C.r=(float *)malloc((C.n+1)*sizeof(float));//
	printf("输入所有圆的半径：\n");
	for(i=1;i<=C.n;i++){
		rf[i]=0;//初始化标记
		scanf("%f",&C.r[i]);
	}
	C.min=MIN;
	min=CirclePerm();
	printf("\n\n最小长度：%f\n",min);

	
	printf("\n\n");
	//printf("排列数：%d\n",n);
	getchar();
	getchar();
	return 0;
} 
