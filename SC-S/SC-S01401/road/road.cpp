#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool mbs;
#define ll long long
const int maxm=1e6+20;
const int maxn=1e4+20;
const int maxk=(1<<10)+2;
int n,m,k,fa[maxn],idx[maxk],c[11];
ll ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct node{int u,v;ll w;}e[maxm],val[maxk][maxn],a[11][maxn];
inline bool cmp(node x,node y){return x.w<y.w;}
inline ll solve(int s){
	ll res=0,las,it1=1,it2=1,cur;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		if((s>>(i-1))&1){
			las=(s^(1<<(i-1))),cur=i;
			break;
		}
	}
	for(int i=1;i<=k;i++) if((s>>(i-1))&1) res+=c[i];
	node now;
	while(it1<=idx[las]||it2<=n){
		if(it1<=idx[las]&&it2<=n){
			if(val[las][it1].w<a[cur][it2].w) now=val[las][it1],it1++;
			else now=a[cur][it2],it2++;
		}
		else if(it1<=idx[las]) now=val[las][it1],it1++;
		else now=a[cur][it2],it2++;
		int x=find(now.u),y=find(now.v);
		if(x==y) continue;
		val[s][++idx[s]]=now,res+=now.w,fa[x]=y;
	}
	return res;
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].w,a[i][j].u=i+n,a[i][j].v=j;
		sort(a[i]+1,a[i]+1+n,cmp);
	} 
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		val[0][++idx[0]]=e[i],ans+=e[i].w,fa[x]=y;
	}
	for(int s=1;s<(1<<k);s++) ans=min(ans,solve(s));
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/