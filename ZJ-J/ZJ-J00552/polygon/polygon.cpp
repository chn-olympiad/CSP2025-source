#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[25];
long long ans;
vector<int> ops;
void dfs(int id,int sum,int mx){
	if(id==n+1){
		if(sum>mx*2)ans=(ans+1)%MOD;
		return ;
	}
	ops.emplace_back(a[id]);
	dfs(id+1,sum+a[id],max(mx,a[id]));
	ops.pop_back();
	dfs(id+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}