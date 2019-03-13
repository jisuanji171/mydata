
#include<stdio.h>

#define N 50

typedef struct SNum{

    int s;                     
    int t;                      

}Num;

Num S[N];

int main(){

    int n,s,i,v,m=0,c=0;

    scanf("%d",&n);

    while(n--){                 

        scanf("%d",&s);         

        for(i=0;i<c;i++){       

            if(s==S[i].s){      

                S[i].t++;       

                if(S[i].t>m)    

                    m=S[i].t;   
                break;

            }

        }

        if(i==c){               
            S[c].s=s;           
            S[c].t=1;           

            c++;                

        }

    }

    v=0x7fffffff;

    for(i=0;i<c;i++){           

        if(S[i].t==m&&S[i].s<v) 

            v=S[i].s;

    }

   printf("从数为：%d\n重数为：%d\n",v,m);


    return 0;

}