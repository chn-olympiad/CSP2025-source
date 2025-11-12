#include<bits/stdc++.h>
#define pi pair <int,int>
#define int long long
#define V vector
#define fi first
#define se second
using namespace std;

const int N = 1e5+11, M = 1e6+11;

int n,m,k,ans=1e18;
int fa[N],C[11],w[11][N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int v,w;
	node(int a,int b){v=a,w=b;}
};
struct edge{
	int u,v,w;
	bool operator < (const edge &a) const{
		return w<a.w;
	}
}add[1100005],add_fi[1100005];
bool vis[N];
int kru(){
	sort(add+1,add+m+1);
	for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
	int cnt=0;
	int res=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		int u=add[i].u,v=add[i].v,w=add[i].w;
		if(vis[u]&&vis[v]){
			if(find(u)==find(v)) continue;
			fa[v]=find(u);
			res+=w,cnt++;
			continue;
		}
		if(!vis[u]&&!vis[v]){
			vis[u]=vis[v]=1;
			fa[v]=u;
			res+=w,cnt++;
//			p[u].push_back(node(v,w));
//			p[v].push_back(node(u,w));
			continue;
		}
		if(!vis[v]){
			vis[v]=1;
			fa[v]=find(u);
			res+=w,cnt++;
//			p[u].push_back(node(v,w));
//			p[v].push_back(node(u,w));
			continue;
		}else{
			vis[u]=1;
			fa[u]=find(v);
			res+=w,cnt++;
//			p[u].push_back(node(v,w));
//			p[v].push_back(node(u,w));
		}
//		cout << res << " 114514 ";
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add[i].u=u,add[i].v=v,add[i].w=w;
		add_fi[i].u=u,add_fi[i].v=v,add_fi[i].w=w;
//		p_have[u].push_back(node(v,w));
//		p_have[v].push_back(node(u,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&C[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&w[i][j]); 
	}
	int new_ans=kru();
	if(new_ans!=0) ans=min(new_ans,ans);
	int C_have=0;
	int sum=0;
//	for(int i=1;i<=n-1;i++) cout << add[i].w << " ",sum+=add[i].w;
//	cout << sum << '\n';
//	cout << new_ans << '\n';
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			add[++m].u=n+1,add[m].v=j,add[m].w=w[i][j];
			add_fi[m].u=n+1,add_fi[m].v=j,add_fi[m].w=w[i][j];
		}
		n++;
//		cout<< "n:" << n << " " << "m:" << m << '\n';
//		for(int j=1;j<=m;j++){
//			cout << add[j].u << " " << add[j].v << " " << add[j].w << '\n';
//		}
		new_ans=kru();//cout << '\n';
//		cout << new_ans << '\n';
		if(new_ans==0) n--,m-=n;
		else{
			if(ans>new_ans+C[i]+C_have) ans=new_ans+C[i]+C_have,C_have+=C[i];
			else n--,m-=n; 
		}
		for(int j=1;j<m;j++){
			add[j].u=add_fi[j].u;
			add[j].v=add_fi[j].v;
			add[j].w=add_fi[j].w;
		}
	}
	printf("%lld",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
// 12pts
/*
5 8 0
1 4 6
2 3 7
4 2 5
4 3 4
1 5 1
5 2 8
5 3 2
5 4 4
*/
