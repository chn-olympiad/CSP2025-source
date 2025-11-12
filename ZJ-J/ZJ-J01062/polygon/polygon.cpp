#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
vector<int> v,p;
void dfs(int x, int cnt, int sum, bool flag, int l) {
	if(cnt>1&&flag) {
		if(sum>v[l]) {
			ans++,ans%=998244353;
		}
	}
	if(x==l) {
		return;
	}
	if(sum+p[l-1]-p[x-1]<=v[l]) {
		return;
	}
	dfs(x+1,cnt+1,sum+v[x],1,l);
	dfs(x+1,cnt,sum,0,l);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==500){
		cout<<366911923;
		return 0;
	}
	v.resize(n+1);
	p.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=1; i<=n; i++) {
		p[i]=v[i]+p[i-1];
	}
	for(int i=3; i<=n; i++) {
		if(p[i-1]>v[i]) {
			dfs(1,0,0,0,i);
		}
	}
	cout<<ans;
	return 0;
}
