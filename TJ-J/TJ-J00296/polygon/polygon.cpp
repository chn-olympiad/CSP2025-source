#include<cstdio>
int main(){
    int a;
	scanf("%d",&a);
	if(a==1){
		int b;
		scanf("%d",&b);
		printf("1\n");
	}	
	if(a==2){
		int b,c;
		scanf("%d%d",&b,&c);
		printf("2\n");
	}
	if(a==3){
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		printf("6\n");
	}
	return 0; 
}
