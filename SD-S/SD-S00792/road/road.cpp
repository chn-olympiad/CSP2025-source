#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=1e10;
void faster(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
struct edge{
	int u,v,w;
};
int n,m,k;
edge ed[N];
int cnt;
int bcj[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int go(int x){
	if(bcj[x]==x) return x;
	else return bcj[x]=go(bcj[x]);
}
bool merge(int x,int y){
	if(go(x)==go(y)) return 1;
	else{
		int o1=go(x);
		int o2=go(y);
		bcj[o1]=o2;
		return 0;
	}
}
signed main(){
	faster();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ed[i]=(edge){u,v,w};
	}
	sort(ed+1,ed+m+1,cmp);
	int cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++) bcj[i]=i;
	for(int i=1;i<=m;i++){
		if(merge(ed[i].u,ed[i].v)){
			continue;
		}
		ans+=ed[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/

