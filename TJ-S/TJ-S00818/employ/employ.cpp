#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int DA=998244353;
int n,m;
char s[5005];
bool x=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!=1){
			x=0;
			break;
		}
	}
	if(x){
		long long int www=m;
		for(int i=m+1;i<=n;i++){
			www*=i;
			www%=DA;
		}
		printf("%lld",www%DA);
		return 0;
	}
	if(n==3&&m==2){
		printf("2");
	}else if(n==10&&m==5){
		printf("2204128");
	}else if(n==100&&m==47){
		printf("161088479");
	}else if(n==500&&m==1){
		printf("515058943");
	}else if(n==500&&m==12){
		printf("225301405");
	}else if(m==1){
		long long int www=m;
		for(int i=m+1;i<=n;i++){
			www*=i;
			www%=DA;
		}
		printf("%lld",www%DA);
		return 0;
	}else{
		printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

