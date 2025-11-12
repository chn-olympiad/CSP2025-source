#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int inf=INT_MAX;
int n,k,x,q[maxn],ans;
map<int,vector<int> > mp;
vector<int> g[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	mp[k].push_back(1);
	for (int i=1;i<=n;++i){
		cin >> x;
		q[i] = int(q[i-1]^x);
		for (int j=0;j<mp[q[i]].size();++j){
			g[mp[q[i]][j]].push_back(i);
		}
		mp[q[i]^k].push_back(i+1);
	}
	int now=1;
	while (now<=n){
		if (g[now].size()==0){
			++now;
			continue;
		}
		int minn=inf;
		for (int i=0;i<g[now].size();++i){
			int v=g[now][i];
			minn = min(minn,v);
		}
		ans++;
		now=minn+1;
	}
	cout << ans;

	return 0;
}

