#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cstdlib>
using namespace std;
long long read(){
	long long dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
long long mod=998244353;
long long n,m,t;
long long a[200004],b[20004];
map<long long ,long long> dp[504];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i,j,k;
	n=read();
	bool flag=true;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1){
			flag=false;
		}
		b[i]=b[i-1]+a[i];
		m=max(m,a[i]);
	}
	if(n<3){
		printf("0");
	}else if(n>3&&flag==false){
		printf("0");
	}else if(n==3){
		if(b[n]>m*2){
			printf("1");
		}else{
			printf("0");
		}
	}else{
		k=n*(n-1)*(n-2)/6;
		for(i=3;i<=n;i++){
			t=(t+k)%mod;
			k=k*(n-i)/(i+1);
			k=k%mod;	
		}
		printf("%lld",t);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

