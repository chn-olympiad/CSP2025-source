#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[5010];
int n;
long long ans=0;
void dfs(int i,int o,int sum,int mx){
	if(i>n){
		if(sum>2*mx&&o>=3){
			ans=(ans+1)%MOD;
		}
		return;
	}
	dfs(i+1,o+1,sum+a[i],a[i]);
	dfs(i+1,o,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f_of_1=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f_of_1=f_of_1&&(a[i]==1);
	}
	if(f_of_1){
		long long num=1;
		for(int i=n;i>=1;i--){
			num=num*i/(n-i+1)%MOD;
			if(i<=(n-2))	ans=(ans+num)%MOD;
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
		cout<<ans;
	}
	return 0;
}
