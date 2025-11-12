#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
const long long N = 2e6;
struct node{
	long long u,v,w;
	bool operator < (const node W)const{
		return w < W.w;
	}
}edges[N],edge[N];
long long fa[N];
long long ans;
long long fin(long long x){
	if(x != fa[x]){
		fa[x] = fin(fa[x]);
	}
	return fa[x];
}
long long minn = 0x3f3f3f3f3f3f3f3f;
long long vis[100];
long long e[100][N]; 

void kus(){
//cout<<endl;
	ans = 0;
	long long cnt_open = 0;
	for(long long i = 1;i <= k;i ++){
		if(vis[i]){
			cnt_open ++;
			ans += e[i][0];
			for(long long j = 1;j <= n;j ++){
				edge[m + n * (cnt_open - 1) + j] = {n + i,j,e[i][j]};
			}
		}
	}
//	cout<<"cnt_open"<<cnt_open<<endl;
	for(long long i = 1;i <= m;i ++){
		edge[i].u = edges[i].u;
		edge[i].v = edges[i].v;
		edge[i].w = edges[i].w;
	}
	sort(edge+1,edge + 1 + m + n * cnt_open);
	for(long long i = 1;i <= m + n * cnt_open;i ++){
//		cout<<"±ß:"<<i<<endl;
	//	cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<endl;
	}
	for(long long i = 1;i <= n + k;i ++){
		fa[i] = i;
	}
	
	long long cnt_vis = 0;
	for(long long i = 1;i <= m + n*cnt_open;i ++){
		long long to = edge[i].v;
		long long be = edge[i].u;
		if(fin(to) != fin(be)){
			
			fa[fin(to)] = fin(be);
			ans += edge[i].w;
			cnt_vis ++;
	//		cout<<"!"<<to<<' '<<be<<endl;
		}
		else{
//			cout<<"OK:"<<to<<' '<<be<<endl;
		}
		if(cnt_vis == n + cnt_open){
	//		cout<<"break";
			break;
		}
	}
	//cout<<"ans"<<' '<<ans<<endl;
}
void dfs(long long x){
	if(x == k + 1){
		kus();
		minn = min(minn,ans);
		return;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	dfs(x + 1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i = 1;i <= m;i ++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edges[i] = {u,v,w};
		
	}
	for(long long i = 1;i <= k;i ++){
		for(long long j = 0;j <= n;j ++){
			scanf("%lld",&e[i][j]);
		}
	}	
	dfs(1);
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

