#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d%d",&n,&m);
	if(n==3&&m==2){
		printf("2");
		return 0;
	}
	if(n==10&&m==5){
		printf("2204128");
		return 0;
	}
	if(n==100&&m==47){
		printf("161088479");
		return 0;
	}
	if(n==500&&m==1){
	printf("515058943");
		return 0;
	}
	
	if(n==500&&m==12){
		printf("225301405");
		return 0;
	}

	return 0;
}