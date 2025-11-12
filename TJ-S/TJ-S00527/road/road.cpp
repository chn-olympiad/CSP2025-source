#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
};
int n,m,k,ans;
road r[1000005];
bool cmp(road a,road b) {
	return a.w<b.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		int tu,tv,tw;
		cin>>tu>>tv>>tw;
		r[i]={tu,tv,tw}; 
	}
	for(int i=1;i<=k;i++) {
		int tmp;
		cin>>tmp;
		for(int j=1;j<=n;j++) {
			cin>>tmp;
		}
	}
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=m;i++) {
		ans+=r[i].w;
	} 
	cout<<ans;
	return 0;
}
