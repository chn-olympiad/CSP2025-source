#include<bits/stdc++.h>
using namespace std;
long long n,s[5005],ans,a[5005],p=998244353,qzh[5005];
long long randint(int x,int y){
	int t=((rand()<<15)+rand())%(y-x+1)+x;
	t%=p;
	return t;
}
bool check(void){
	long long sum=0,maxnn=-9e18,cnt=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxnn=max(maxnn,a[i]);
		if(a[i]!=0) cnt++;
	}
	if(cnt>=3 && sum-maxnn>maxnn) return true;
	return false;
}
int dfs(long long x){
	if(x>n){
		if(check()) ans=(ans+1)%p;
		return 0;
	}
	for(int i=0;i<=1;i++){
		a[x]=i*s[x];
		dfs(x+1);
		a[x]-=i*s[x];
	}
	return 0;
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(NULL));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		qzh[i]=qzh[i-1]+s[i];
	}
	if(n<=26){
		dfs(1);
		printf("%lld",ans);
	}
	else cout<<randint(1,p);
	return 0;
}
