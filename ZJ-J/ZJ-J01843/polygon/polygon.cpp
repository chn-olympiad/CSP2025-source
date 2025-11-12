#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,a[5005];
long long ans;
void dfs(int dep,int pre,int maxn){
	if(dep>n){
		if(pre>maxn*2)ans++;
		ans%=MOD;
		return;
	}
	dfs(dep+1,pre,maxn);
	dfs(dep+1,pre+a[dep],max(maxn,a[dep]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}