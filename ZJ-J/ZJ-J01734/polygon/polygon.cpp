#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+5,mod=998244353;
int n,a[N],flag;
long long ans;
map<int,long long>mp;
long long Pow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);mp[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)flag=1;
	}sort(a+1,a+n+1);
	if(!flag){
		ans=n;
		printf("%lld",(Pow(2,ans)-1ll-ans-(ans*(ans-1)%mod)*Pow(2,mod-2)%mod+mod)%mod);
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<pair<int,long long> >ve;
		for(auto it:mp){
			if(it.first>a[i])ans=(ans+it.second)%mod;
			ve.push_back({it.first,it.second});
		}
		for(auto j:ve){
			mp[j.first+a[i]]=(mp[j.first+a[i]]+j.second)%mod;
		}
	}printf("%lld",ans);
	return 0;
}
