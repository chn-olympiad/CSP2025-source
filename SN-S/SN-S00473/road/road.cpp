#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int ans=0;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		ans+=z;
	}
	cout<<ans<<"\n";
	return 0;
}
