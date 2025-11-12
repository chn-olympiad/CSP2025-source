#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[10005];
long long ans,c[15],a[15][10005];
bool sxt;
priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,greater<pair<long long,pair<int,int> > > >q;
int find(int x) {
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y;
		long long w;
		cin>>x>>y>>w;
		q.push({w,{x,y}});
	}
	sxt=0;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0)sxt=1;
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			if(a[i][j]!=0)sxt=1;
		}
	}
	if(k>0&&sxt==0) {
		cout<<0;
		return 0;
	}
	if(k>0) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				long long w=9e18;
				for(int g=1; g<=k; g++) {
					w=min(w,a[g][i]+c[g]+a[g][j]);
				}
				q.push({w,{i,j}});
			}
		}
	}
	for(int i=1; i<=n; i++)fa[i]=i;
	while(cnt<n-1) {
		long long w=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		int xfa=find(x);
		int yfa=find(y);
		if(xfa!=yfa) {
			fa[yfa]=xfa;
			cnt++;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}
