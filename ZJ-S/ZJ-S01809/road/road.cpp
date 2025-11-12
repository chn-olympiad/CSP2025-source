#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
struct Edge{
	int pre, to, val;
}a[M<<2];
int cnt;
int c[N];
void add(int pre, int to, int val){
	a[++cnt].pre=pre;
	a[cnt].to=to;
	a[cnt].val=val;
	return;
}
bool cmp(Edge i,Edge j){
	return i.val<j.val;
}
int fa[N];
bool fix[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			add(i+n,j,x+c[i]);
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(find(a[i].pre)==find(a[i].to)) continue;
		ans+=a[i].val;
		if(a[i].pre>n){
			if(!fix[a[i].pre]){
				ans+=c[a[i].pre];
				fix[a[i].pre]=1;
			}
		}
		if(a[i].to>n){
			if(!fix[a[i].to]){
				ans+=c[a[i].to];
				fix[a[i].to]=1;
			}
		}
		//cout<<a[i].pre<<' '<<a[i].to<<'\n';
		fa[find(a[i].pre)]=find(a[i].to);
	}
	cout<<ans;
	return 0;
}
