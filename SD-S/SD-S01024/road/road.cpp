#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int read(){
	int w=0,k=1;
	char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10+c-'0';c=getchar();}
	return w*k;
}
int _read(){
	int x;
	cin>>x;
	return x;
}
int n,m,k;
struct Edge{
	int u,v,w;
}edge[1000010],d[200050];
vector<pii>e[100010];
int fa[100010],siz[100010];
int a[12][10010],c[12];
int find(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=find(fa[x]);
}
void mege(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(siz[x]>siz[y])swap(x,y);
	siz[y]+=siz[x];
	fa[x]=y;
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	sort(edge+1,edge+m+1,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int x=edge[i].u,y=edge[i].v,w=edge[i].w;
		if(find(x)!=find(y)){
			e[x].push_back({y,w});
			e[y].push_back({x,w});
			mege(x,y);
			++cnt;ans+=w; 
			edge[cnt].u=x,edge[cnt].v=y,edge[cnt].w=w;
		}
		if(cnt==n-1)break;
	}
//	return 0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
//	if(!(n>1000&&k>5)){
		for(int s=0;s<(1<<k);s++){
			ll res=0,r=cnt;
			for(int i=0;i<=n+k;i++)fa[i]=i;
			for(int i=1;i<=cnt;i++)d[i]=edge[i];
			for(int i=1;i<=k;i++){
				if(s&(1<<(i-1))){
					for(int j=1;j<=n;j++)
						d[++r]=(Edge){n+i,j,a[i][j]};
					res+=c[i];	
				}
			}
			sort(d+1,d+r+1,cmp);
			int ct=0;
			for(int i=1;i<=r;i++){
				int x=d[i].u,y=d[i].v,w=d[i].w;
				if(x<=n&&y<=n)ct++;
				if(find(x)!=find(y)){
					mege(x,y);
					res+=w;
				}
				if(res>ans)break;
				if(ct==n-1)break;
			}
			ans=min(ans,res); 
		}
		cout<<ans<<endl;
		return 0;
		// 75pts
		// 1.332s? 
//	}
	return 0;
}

