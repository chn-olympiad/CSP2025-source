#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5005,mod=998244353;
long long n,a[MAXN];
long long dfs(long long p,long long sum,long long mx){
	if(p>n){
		return sum>mx*2;
	}
	return (dfs(p+1,sum,mx)+dfs(p+1,sum+a[p],a[p]))%mod;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<dfs(1,0,0)%mod<<"\n";
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}