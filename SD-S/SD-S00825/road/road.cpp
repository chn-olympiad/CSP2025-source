#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],tot,a[1100000][20],ans=0x3f3f3f3f,head[1100000],vis[1100000];
vector<int> q;
struct node{
	int v,nxt,w;
}g[1100000];
struct nodee{
	int c,a[20];
}cit[1100000];
bool cmp(nodee x,nodee y){
	return x.c<y.c;
}
void add(int u,int v,int w){
	g[++tot]={v,head[u],w};
	head[u]=tot;
}
void dfs(int x){
	if(q.size()>n){
		int sum=0;
		for(int i=0;i<q.size();i++){
			sum+=q[i];
		}
		ans=min(ans,sum);
		return ;
	}
	for(int i=head[x];i;i=g[i].nxt){
		q.push_back(g[i].w);
		vis[g[i].v]=1;
		dfs(g[i].v);
		vis[g[i].v]=0;
		q.pop_back();
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cit[i].c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&cit[i].a[j]);
			/*a[i][j]+=c[i];
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);*/
		}
	}
	sort(cit+1,cit+1+k,cmp);
	if(k==0){
		dfs(1);
		printf("%lld",ans);
	}else{
	
		for(int l=1;l<=k;l++){
			int sum=0;
			for(int j=1;j<=n;j++){
			cit[l].a[j]+=cit[l].c;
			add(n+l,j,cit[l].a[j]);
			add(j,n+l,cit[l].a[j]);
		}
		for(int i=1;i<=n;i++){
			int bian=g[head[i]].w;
			for(int j=head[i];j;j=g[j].nxt){
				bian=min(g[j].w,bian);
			}
			sum+=bian;
		}//ans=min(ans,sum);
		if(ans>=sum){
				ans=sum-cit[l].c;//cout<<cit[l].c<<"e "<<ans<<endl;
			}
		}
		printf("%lld",ans);
	}
	
	return 0;
 }


