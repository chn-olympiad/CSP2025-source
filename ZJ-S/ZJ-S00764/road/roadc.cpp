//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e4+20,M=1e6+20;
//int read(){
//	int x=0,f=1;
//	char c=getchar();
//	for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
//	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
//	return x*f;
//}
//bool uu;
//int b[20*N],totc,mp[20*N],len;
//int c[20][N];
//int n,m,k,fa[N],tot,fa2[N],tong[N],tongx[N];
//bool vis[N];
//int find(int x){
//	if(fa[x]==x)return x;
//	return fa[x]=find(fa[x]);
//}
//int find2(int x){
//	if(fa2[x]==x)return x;
//	return fa2[x]=find2(fa2[x]);
//}
//struct edges{
//	int u,e,w;
//}ed[M],edn[M],ed2[M];
//bool cmp(edges a,edges b){
//	return a.w<b.w;
//}
//long long ret=2e18;
//void krus(){
//	for(int i=1;i<=m;i++){
//		int u=find(ed[i].u),e=find(ed[i].e);
//		if(e==u)continue;
//		fa[u]=e;
//		edn[++tot]=ed[i];
//		if(tot==n-1)break;
//	}
//	return;
//}
//vector<pair<int,int> >v[N*20];
//void dfs(int u){
//	if(u==k+1){
//		for(int i=1;i<=n+k;i++)fa2[i]=i,tong[i]=tongx[i]=0;
//		int tt=0;
//		long long sum=0;
//		for(int i=1;i<n;i++)v[edn[i].w].push_back(make_pair(edn[i].u,edn[i].e));
//		for(int i=1;i<=k;i++){
//			if(vis[i]){
//				sum+=c[i][0];
//				for(int j=1;j<=n;j++){
//					v[c[i][j]].push_back(make_pair(n+i,j));
//				}
//			}
//		}
//		int toto=0;
//		for(int i=1;i<=len;i++){
//			for(auto e:v[i]){
//				int u=find2(e.first),ee=find2(e.second);
//				if(ee==u)continue;
//				if(e.first<=n&&e.second<=n)toto++;
//				fa2[u]=ee;
//				sum+=mp[i];
//				tong[e.first]++;tong[e.second]++;
//				tongx[e.first]=tongx[e.second]=mp[i];
//				if(toto==n-1)break;
//			}
//			if(toto==n-1)break;
//		}
//		ret=min(ret,sum);
//		for(int i=1;i<=len;i++)v[i].clear();
//		return;
//	}
//	dfs(u+1);
//	vis[u]=1;
//	dfs(u+1);
//	vis[u]=0;
//	return;
//}
//void ini(){
//	for(int i=1;i<n;i++){
//		b[++totc]=edn[i].w;
//	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			b[++totc]=c[i][j];
//		}
//	}
//	sort(b+1,b+1+totc);
//	len=unique(b+1,b+1+totc)-b-1;
//	for(int i=1;i<n;i++){
//		int o=edn[i].w;
//		edn[i].w=lower_bound(b+1,b+1+len,o)-b;
//		mp[edn[i].w]=o;
//	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			int o=c[i][j];
//			c[i][j]=lower_bound(b+1,b+1+len,o)-b;
//			mp[c[i][j]]=o;
//		}
//	}
//	return;
//}
//bool ee;
//signed main(){
//	freopen("rand.in","r",stdin);
//	n=read();m=read();k=read();
//	for(int i=1;i<=n;i++)fa[i]=i;
//	for(int i=1;i<=m;i++){
//		ed[i].u=read();ed[i].e=read();ed[i].w=read();
//	}
//	for(int i=1;i<=k;i++){
//		for(int j=0;j<=n;j++){
//			c[i][j]=read();
//		}
//	}
//	sort(ed+1,ed+1+m,cmp);
//	krus();
//	ini();
//	dfs(1);
//	printf("%lld",ret);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1e6+20;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
bool uu;
int b[20*N],totc,mp[20*N],len;
int c[20][N];
int n,m,k,fa[N],tot,fa2[N],tong[N],tongx[N];
bool vis[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int find2(int x){
	if(fa2[x]==x)return x;
	return fa2[x]=find2(fa2[x]);
}
struct edges{
	int u,e,w;
}ed[M],edn[M],ed2[M];
bool cmp(edges a,edges b){
	return a.w<b.w;
}
long long ret=2e18;
void krus(){
	for(int i=1;i<=m;i++){
		int u=find(ed[i].u),e=find(ed[i].e);
		if(e==u)continue;
		fa[u]=e;
		edn[++tot]=ed[i];
		if(tot==n-1)break;
	}
	return;
}
vector<pair<int,int> >v[N*20];
void dfs(int u,long long ss){
	if(u==k+1){
		for(int i=n+k;i>=1;i--)fa2[i]=i,tong[i]=tongx[i]=0;
		long long sum=ss;
		int toto=0;
		for(int i=1;i<=len;i++){
			for(auto e:v[i]){
				int u=find2(e.first),ee=find2(e.second);
				if(ee==u)continue;
				if(e.first<=n&&e.second<=n)toto++;
				fa2[u]=ee;
				sum+=mp[i];
				tong[e.first]++;tong[e.second]++;
				tongx[e.first]=tongx[e.second]=mp[i];
				if(toto==n-1)break;
			}
			if(toto==n-1)break;
		}
		ret=min(ret,sum);
		return;
	}
	dfs(u+1,ss);
	vis[u]=1;
	for(int j=1;j<=n;j++){
		v[c[u][j]].push_back(make_pair(n+u,j));
	}
	dfs(u+1,ss+c[u][0]);
	for(int j=1;j<=n;j++){
		v[c[u][j]].pop_back();
	}
	vis[u]=0;
	return;
}
void ini(){
	for(int i=1;i<n;i++){
		b[++totc]=edn[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			b[++totc]=c[i][j];
		}
	}
	sort(b+1,b+1+totc);
	len=unique(b+1,b+1+totc)-b-1;
	for(int i=1;i<n;i++){
		int o=edn[i].w;
		edn[i].w=lower_bound(b+1,b+1+len,o)-b;
		mp[edn[i].w]=o;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int o=c[i][j];
			c[i][j]=lower_bound(b+1,b+1+len,o)-b;
			mp[c[i][j]]=o;
		}
	}
	return;
}
bool ee;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		ed[i].u=read();ed[i].e=read();ed[i].w=read();
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			c[i][j]=read();
		}
	}
	sort(ed+1,ed+1+m,cmp);
	krus();
	ini();
	for(int i=1;i<n;i++)v[edn[i].w].push_back(make_pair(edn[i].u,edn[i].e));
	dfs(1,0);
	printf("%lld",ret);
	return 0;
}
