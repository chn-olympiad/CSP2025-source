#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],b[500005];
vector<int> e[1100000];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	e[0].push_back(0);
	for(int i=1; i<=n; i++)
		cin>>a[i],b[i]=a[i]^b[i-1],e[b[i]].push_back(i);
	int pre=0,ans=0;
	for(int i=1; i<=n; i++) {
		int p=lower_bound(e[k^b[i]].begin(),e[k^b[i]].end(),pre)-e[k^b[i]].begin();
		if(p==e[k^b[i]].size()||e[k^b[i]][p]>=i)continue;
		ans++,pre=i;
	}
	cout<<ans;
	return 0;
}
