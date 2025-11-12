#include<cstdio>
#include<stdlib.h>
#include<time.h>
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(NULL));
	scanf("%d",&n);
	if(n<=10)printf("%d\n",rand()%10);
	else if(n<=18)printf("%d\n",rand()%20+10);
	else if(n<=100)printf("%d\n",rand()%1000+100);
	else printf("%d\n",rand()%10000*100000+rand());
	return 0;
}
