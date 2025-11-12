#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
const int MAXN=1e6+10;
const int mod=998244353;

bool awa;
int n,m,k,fa[MAXN],c[MAXN];
long long dp[1<<10];
bool vis[MAXN][11];
struct node{
	int u,v,w;
}e[MAXN];
vector<node> b,h,val[11],edge[1<<10];

bool cmp(node n1,node n2){
	return n1.w<n2.w;
}

int find(int u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}

long long kru(int id,int N){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(h.begin(),h.end(),cmp);
	long long ans=0,cnt=0;
	for(node i:h){
		int u=i.u,v=i.v,w=i.w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			edge[id].push_back(i);
			ans+=w;
		}
		if(cnt==N-1) break;
	}
	return dp[id]=ans;
}
bool qwq;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road4.in","r",stdin);
//	freopen("road4.out","w",stdout);
//	cout<<(&awa-&qwq)/1024.0/1024.0<<endl;
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) val[i].push_back((node){n+i,j,read()});
		sort(val[i].begin(),val[i].end(),cmp);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1,cnt=0;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			ans+=w;
			b.push_back(e[i]);
		}
		if(cnt==n-1) break;
	}
	dp[0]=ans;
	edge[0]=b;
	for(int i=1;i<(1<<k);i++){
		long long sum=0,cnt=0,minval=1e18,pos;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				cnt++;
				sum+=c[j+1];
				if(dp[i^(1<<j)]<minval){
					minval=dp[i^(1<<j)];
					h=edge[i^(1<<j)];
					pos=j+1;
				}
			}
		}
		int p1=0,p2=0;
		vector<node> res;
		while(p1<h.size()&&p2<n) res.push_back(h[p1].w<val[pos][p2].w?h[p1++]:val[pos][p2++]);
		while(p1<h.size()) res.push_back(h[p1++]);
		while(p2<n) res.push_back(val[pos][p2++]);
		h=res;
		ans=min(ans,sum+kru(i,n+cnt));
	}
	cout<<ans;
	return 0;
}
