#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998224353;
int n,a[5005],ans;
vector<int> v;
void dfs(int p,int sum){
	if(p==n+1){
		if(v.size()<3)return;
		if(sum>v[v.size()-1]*2)
			ans=(ans+1)%mod;
		return;
	}
	v.push_back(a[p]);
	dfs(p+1,sum+a[p]);
	v.pop_back();
	dfs(p+1,sum);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0);
	cout<<ans;
	return 0;
}
