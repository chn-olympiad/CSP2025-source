#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 _i;
const LL mod=998244353;
LL n,a[5005];
bool cmp(LL x,LL y){
	return x>=y;
}
LL give(_i ans){
	LL p=0;
	stack<short>s;
	while(ans){
		s.push(ans%10);
		ans/=10;
	}
	while(!s.empty()){
		p=p*10+s.top();
		s.pop();
	}
	return p;
}
LL sum(LL n){
	_i now=n*(n-1)*(n-2)/6;
	_i ans=now;
	for(int i=3;i<=n-1;i++){
		now=now*(n-i)/(i+1);
		ans=(ans+now)%mod;
	}
	return give(ans);
}
LL dfs(LL now,LL res,LL cnt,LL choose){
	if(cnt>res){
		LL p=sum(n-now+1);
		LL q=n-now+1;
		LL q1=q*(q-1)/2;
		p=((p+q)%mod+q1)%mod;
		if(choose>=2)
			p=(p+1)%mod;
		return p;
	}
	if(now>n&&choose>=2)
		return ((cnt>res)?1:0);
	LL p=0;
	for(int i=now;i<=n;i++)
		p=(p+dfs(i+1,res,cnt+a[i],choose+1))%mod;
	return p;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	LL maxn=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(a[i]>maxn)
			maxn=a[i];
	}
	if(maxn==1){
		printf("%lld",sum(n)); 
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	LL ans=0;
	for(int i=1;i<=n-2;i++)
		ans=(ans+dfs(i+1,a[i],0,0))%mod;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
