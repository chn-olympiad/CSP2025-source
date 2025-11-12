#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define lowbit(x) ((x)&(-(x)))
const ll inf=1e18;
const int N=1e4+50,M=1e6+10,inf1=2e9;
int www[11],fa[N],s[N],pos[11];
struct edge{
	int u,v,w;
	bool operator <(const edge &t)const{
		return w<t.w;
	}
}e[11][N],e1[M];
int fi(int x){
	return fa[x]==x?x:fa[x]=fi(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e1[i].u>>e1[i].v>>e1[i].w;
	for(int i=0;i<k;i++){
		cin>>www[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			e[i][j].u=n+i+1,e[i][j].v=j,e[i][j].w=x;
		}
		sort(e[i]+1,e[i]+n+1);
	}
	sort(e1+1,e1+1+m);
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=fi(e1[i].u),y=fi(e1[i].v);
		if(x!=y) fa[x]=y,e[k][++cnt]=e1[i];
	}
	k++;
	ll ans=inf;
	for(int i=(1<<(k-1));i<(1<<k);i++){
		ll tmp=0;int tot=n-1;
		for(int j=0;j<k;j++) if((i>>j)&1) tot++,tmp+=www[j];
		for(int j=0;j<k;j++) pos[j]=1;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<tot;j++){
			int u1=1,v1=1,w1=inf1;
			for(int p=0;p<k;p++){
				if((i>>p)&1){
					int lim=(p==k-1?n:n+1);
					while(pos[p]<lim&&fi(e[p][pos[p]].u)==fi(e[p][pos[p]].v)) pos[p]++;
					if(pos[p]<lim&&e[p][pos[p]].w<w1) w1=e[p][pos[p]].w,u1=e[p][pos[p]].u,v1=e[p][pos[p]].v;
				}
			}
			fa[fi(u1)]=fi(v1),tmp+=w1;
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}
