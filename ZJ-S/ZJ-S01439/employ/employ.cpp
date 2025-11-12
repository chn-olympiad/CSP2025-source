#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,a[510];
stack<int>s;
bool vis[510];
string s1;
vector<int>v;
void dfs(int now) {
	if(now==n) {
		v.clear();
		while(s.size()) {
			v.push_back(s.top());
			s.pop();
		}
		int oz=0,l=0;
		for(int i=1; i<=n; i++) {
			s.push(v[n-i]);
			if(oz>=a[v[i-1]]||s1[i-1]=='0')oz++;
			else l++;
		}
		if(l>=m) {
			ans++;
			//	for(int i=0;i<n;i++)cout<<v[i]<<' ';
			//		cout<<'\n';
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1,s.push(i);
			dfs(now+1);
			vis[i]=0,s.pop();
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1; i<=n; i++)cin>>a[i];
	dfs(0);
	cout<<ans;
	return 0;
}
