#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k,side;

struct node{
	int u,v,w;
	int p;
}e[N];

int fa[N];
int c[114],a[114][N];
int f[114],vis[114];
int tot;

int find(int x){
	if(x!=fa[x]){
		return x=find(fa[x]);
	}
	return x;
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}

bool cmp(node x,node y){
	return x.w<y.w;
}

int pay(int x,int ft){
	
	for(int i=1;i<=n+x;i++){
		fa[i]=i;
	}
	
	sort(e+1,e+m+x*n+1,cmp);
	
	int ans=0,len=0,ad=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m+n*x;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w,p=e[i].p;
//		cout<<x<<" "<<u<<" "<<v<<" "<<w<<'\n';
		u=find(u);
		v=find(v);
		
		if(u!=v){
			if(p!=0&&vis[p]==0){
				vis[p]=1;
				ad++;
				ans+=c[p];
			}
			add(u,v);
			ans+=w;
			len++;
			if(len==n-1+side+ad)break;
		}
	}
//	cout<<x<<" "<<ans<<'\n';
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	tot=m;
	int flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flag=1;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[++tot].u=i+n;
			e[tot].v=j;
			e[tot].w=w;
			e[tot].p=i;
		}
	}
	f[0]=pay(0,0);
	for(int i=1;i<=k;i++){
		f[i]=min(f[i-1],pay(i,f[i-1]));
	}
	cout<<f[k];
	return 0;
}

