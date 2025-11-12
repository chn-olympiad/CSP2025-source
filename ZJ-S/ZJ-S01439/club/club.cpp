#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[101010][4];
vector<int>e[4];
vector<int>v;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0;
		e[1].clear(),e[2].clear(),e[3].clear();
		v.clear();
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3])))e[1].push_back(i),ans+=a[i][1];
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3])))e[2].push_back(i),ans+=a[i][2];
			else e[3].push_back(i),ans+=a[i][3];
		}
		int oz=0;
		if(e[1].size()>n/2)oz=1;
		if(e[2].size()>n/2)oz=2;
		if(e[3].size()>n/2)oz=3;
		if(oz==0) {
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0; i<e[oz].size(); i++) {
			int minn=1e18;
			if(oz!=1&&a[e[oz][i]][oz]-a[e[oz][i]][1]<minn) {
				minn=a[e[oz][i]][oz]-a[e[oz][i]][1];
			}
			if(oz!=2&&a[e[oz][i]][oz]-a[e[oz][i]][2]<minn) {
				minn=a[e[oz][i]][oz]-a[e[oz][i]][2];
			}
			if(oz!=3&&a[e[oz][i]][oz]-a[e[oz][i]][3]<minn) {
				minn=a[e[oz][i]][oz]-a[e[oz][i]][3];
			}
			v.push_back(minn);
		}
		sort(v.begin(),v.end());
		for(int i=0; i<e[oz].size()-n/2; i++) {
			ans-=v[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
