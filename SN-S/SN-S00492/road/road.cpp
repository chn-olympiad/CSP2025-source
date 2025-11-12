#include<bits/stdc++.h>
#define int long long
using namespace std;

struct road {
	int x,y,m;//xµ½y mÔª
} r[1111111];

int n,m,k,ans=0;
int c[20],a[1111111],mn[1111111];

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mn,0x3f,sizeof mn);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>r[i].x>>r[i].y>>r[i].m;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int i=1; i<=m; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=m; i++) {
			mn[i]=min(r[i].m,a[r[i].x]+a[r[i].y]);
		}
	}
	for(int i=1; i<=m; i++) {
		ans+=mn[i];
	}
	cout<<ans;
	return 0;
}
