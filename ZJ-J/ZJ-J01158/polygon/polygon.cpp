#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
LL ans,n,a[5514];
bool cnt[5514];
LL fpow(LL x,LL y){
	LL _ans=1,_pow=x;
	while(y){
		if(y&1)
		_ans=_ans*_pow%mod;
		_pow=_pow*_pow%mod;
		y>>=1;
	}
	return _ans;
}
void dfs(LL x,int n_x,int n_max){
	for(int i=n_x+1;i<n_max;i++){
		if(cnt[i])continue; 
		cnt[i]=1;
		n_x=i;
		LL tmp=x+a[i];
		if(tmp>a[n_max]){
			int tmp2=0;
			for(int j=n_x;j<n_max;j++)
			if(!cnt[j])tmp2++;
			ans=(ans+fpow(2,tmp2))%mod;
		}
		else
		dfs(tmp,n_x,n_max);
		cnt[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<i-1;j++){
			memset(cnt,0,sizeof(cnt));
			cnt[j]=1;
			dfs(a[j],j,i);
			cnt[j]=0;
		}
	}
	cout<<ans%mod;
}
