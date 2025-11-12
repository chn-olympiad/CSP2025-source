#include<bits/stdc++.h>
#define int long long
#define fup(a,b,c,d) for(int a=b;a<=c;a+=d)
#define pii pair<int,int>
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
const int N=1e6+10+5e3+10;
const int INF=0x3f3f3f3f;
int n,m,k,ans=INF;
int c[N],a[12][N],fa[N];
struct Edge{
	int u,v,w;
	bool operator<(const Edge &rhs)const{
		return w<rhs.w;
	}
}e[N],ch[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	fa[x]=y;
}
int vis[12];
void dfs(int pos){
	if(pos==n+1){
		int sum=0,top=m,tot=n;
		
		fup(i,1,n,1)fa[i]=i;
		fup(i,1,m,1)ch[i]=e[i];
		fup(i,1,k,1){
			if(vis[i]){
				sum+=c[i];fa[++tot]=tot;
				fup(j,1,n,1)
					ch[++top]={tot,j,a[i][j]};
			}
		}
		sort(ch+1,ch+1+top);
		fup(i,1,top,1){
			if(find(ch[i].u)==find(ch[i].v))continue;
			sum+=ch[i].w;
			merge(ch[i].u,ch[i].v);
		}
		ans=min(ans,sum);
		return ;
	}
	vis[pos]=0;dfs(pos+1);
	vis[pos]=1;dfs(pos+1);vis[pos]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	fup(i,1,m,1){
		int u,v,w;cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	if(k==0){
		sort(e+1,e+1+m);
		fup(i,1,n,1)fa[i]=i;
		fup(i,1,m,1){
			if(find(e[i].u)==find(e[i].v))continue;
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
		cout<<ans;
	} 
	else{
		fup(i,1,k,1){
			cin>>c[i];
			fup(j,1,n,1)cin>>a[i][j];
		}
		dfs(1);
		cout<<ans;
	}
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
