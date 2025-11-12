#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=2e6+10,MAXN=1e5+10;
struct Node{
	int u,v;
	double w;
}edges[INF];

double c[15],way[15],ans,tmp;
bool used[15];
int book[MAXN],fa[MAXN],cnt;
int n,m,k;
bool cmp(const Node a1,const Node a2){
	return a1.w<a2.w;
}

int sfind(int x){
	if (fa[x]!=x)fa[x]=sfind(fa[x]);
	return fa[x];
}

void work1(){
	for (int i=1;i<=k;i++){
		if (i!=1)cin>>c[i];
		for (int j=1;j<=n;j++){
			int w;cin>>w;
			edges[++cnt]={n+i,j,1.0*w+c[i]/2};
		}
	}
	sort(edges+1,edges+1+cnt,cmp);
	for (int i=1;i<=cnt;i++){
		int x=edges[i].u,y=edges[i].v;
		int root1=sfind(x),root2=sfind(y);
		if (root1==root2)continue;
		fa[root1]=root2;
		book[x]++,book[y]++;
		if (n+1<=x&&x<=n+k)way[x-n]=edges[i].w;
		if (n+1<=y&&y<=n+k)way[y-n]=edges[i].w;
		ans+=edges[i].w;
	}
	for (int i=n+1;i<=n+k;i++){
		if (book[i]==0||book[i]==2)continue;
		if (book[i]==1)ans-=way[i-n];
		if (book[i]>2)ans-=(book[i]-2)*(c[i-n]/2.0);
	}
	long long tot=ans;
	cout<<tot;
}
inline void check(double x){
	double num=x;
	for (int i=1;i<=n+k;i++)fa[i]=i;
	for (int i=1;i<=cnt;i++){
		int x=edges[i].u,y=edges[i].v;
		if ((n+1<=x&&x<=n+k&&!used[x-n])||(n+1<=y&&y<=n+k&&!used[y-n]))continue;
		int root1=sfind(x),root2=sfind(y);
		if (root1==root2)continue;
		fa[root1]=root2;
		num+=edges[i].w;
	}
	//cout<<num<<"\n";
	ans=min(ans,num);
}
void dfs(int x){
	if (x==k+1){
		check(tmp);
		return;
	}
	used[x]=1,tmp+=c[x];
	if (tmp<ans)dfs(x+1);
	used[x]=0,tmp-=c[x];
	dfs(x+1);
}
void work2(){
	ans=LONG_LONG_MAX;
	for (int i=1;i<=k;i++){
		if (i!=1)cin>>c[i];
		for (int j=1;j<=n;j++){
			int w;cin>>w;
			edges[++cnt]={n+i,j,1.0*w};
		}
	}
	sort(edges+1,edges+1+cnt,cmp);
	dfs(1);
	long long tot=ans;
	cout<<tot;
}
bool flag=false;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	if (1ll*(1<<k)*(m+(n*k))>500000000)flag=1;
	for (int i=1;i<=n+k;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		edges[++cnt]={u,v,1.0*w};		
	}
	cin>>c[1];
	if (c[1]==0)flag=1;
	if (flag)work1();
	else work2();
	return 0;
}
