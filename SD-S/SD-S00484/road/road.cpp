#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f; 
const int N=2e4+4;
const int M=2e6+6;
int n,m,k,tot,cnt,minn=INF,fa[N],c[20],qu[M],a[20][N],p[20],vil[M],s[N],sum,x,y,z,cnt_used[20],re[20];
bool vis[M],v[20],used[M],use[20];
struct Edge{
	int u,v;
}e[M];
struct node{
	int id,w;
	bool operator<(const node&p)const{
		return w>p.w;
	}
};
int findf(int x){
	if(x==fa[x]) return fa[x];
	else return fa[x]=findf(fa[x]);
}
priority_queue<node>q,q1;
void solve(){
	cnt=n;sum=0;
	while(!q.empty()){
		node nw=q.top();
		int id=nw.id,w=nw.w;
		q.pop();
		used[id]=1;
		if(vis[id]) continue;
		int fx=findf(e[id].u),fy=findf(e[id].v);
		if(fx!=fy){
			fa[fx]=fy;
			s[fy]+=s[fx];
			sum+=w;
			if(vil[id]&&!v[vil[id]]){
					cnt++;
					int j=vil[id];
					v[j]=1;
					for(int i=p[j];i<=p[j]+n-1;i++){
						if(used[i]) continue;
		//					vis[i]=1;
						vil[i]=0;
						e[++tot]=e[i];
						q.push({tot,a[j][i-p[j]+1]});
						vil[tot]=j;
					}
			}
			if(s[fy]==cnt) break;
		}
	}
	minn=min(minn,sum);
}
void init(){
	for(int i=1;i<=m;i++){
		q.push({i,qu[i]});
		used[i]=0;
	}
	for(int i=1;i<=k;i++){
		if(!use[i]) continue;
		for(int j=p[i];j<=p[i]+n-1;j++){
			used[j]=0;
			q.push({j,a[i][j-p[i]+1]+c[i]});
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i,s[i]=1;
	for(int i=1;i<=k;i++){
		use[i]=vis[i]=v[i]=0;
	}
	solve();
}

void dfs(int x){
	if(x>k){
		init();
		return ;
	}
	use[x]=0;
	dfs(x+1);
	use[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i,s[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		qu[i]=z;
		e[++tot]={x,y};
//		q.push({tot,z});
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		bool flag1=1;
		scanf("%lld",&c[i]);
		if(c[i]) flag1=0;
		p[i]=tot+1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]) flag1=0;
			e[++tot]={i+n,j};
			vil[tot]=i;
//			q.push({tot,a[i][j]+c[i]});
		}
		if(flag1) flag=1;
	}
	if(k==0){
		for(int i=1;i<=m;i++) q.push({i,qu[i]});
		cnt=n;
		while(!q.empty()){
			node nw=q.top();
			int id=nw.id,w=nw.w;
			q.pop();
			used[id]=1;
			if(vis[id]) continue;
			int fx=findf(e[id].u),fy=findf(e[id].v);
			if(fx!=fy){
				fa[fx]=fy;
				s[fy]+=s[fx];
				sum+=w;
				if(vil[id]){
					cnt_used[vil[id]]++;
					re[vil[id]]=w;
					if(!v[vil[id]]){
						cnt++;
						int j=vil[id];
						v[j]=1;
						for(int i=p[j];i<=p[j]+n-1;i++){
							if(used[i]) continue;
		//					vis[i]=1;
							vil[i]=0;
							e[++tot]=e[i];
							q.push({tot,a[j][i-p[j]+1]});
							vil[tot]=j;
						}
					}
				}
				if(s[fy]==cnt) break;
			}
		}
		printf("%lld",sum);
	}else if((m<=100000&&k<=5)||(m<=1000000&&k<=5)){
		dfs(1);
		printf("%lld",minn);
	}else if(flag){
		printf("0");
	}else{
		for(int i=1;i<=m;i++){
			q.push({i,qu[i]});
		}
		for(int i=1;i<=k;i++){
			for(int j=p[i];j<=p[i]+n-1;j++){
				q.push({j,a[i][j-p[i]+1]+c[i]});
			}
		}
		solve();
		printf("%lld",minn);
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
