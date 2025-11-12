#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1200020;
int n,m,k;
int c[15][N];
int idx=0;
struct nd{
	int u,v,w;
}eg[M],eg2[11*N],eg3[11*N];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
int f[N];
int getf(int t){
	if(t==f[t])return t;
	f[t]=getf(f[t]);
	return f[t];
}
int w0[15];
long long ans=0x3f3f3f3f3f3f3f3f;
long long solve(int sump){
	long long res=0;
	for(int i=1;i<=sump;i++){
		f[i]=i;
	}
	memcpy(eg3,eg2,sizeof eg2);
	sort(eg3+1,eg3+idx+1,cmp);
	for(int i=1;i<=idx;i++){
		int u=eg3[i].u,v=eg3[i].v,w=eg3[i].w;
		//cout<<u<<"->"<<v<<":"<<w<<" ";
		if(getf(u)!=getf(v)){
			f[getf(u)]=getf(v);
			res+=w;
		}
	}
	return res;
}
void dfs(int t,long long res,int sump){
	if(t==k+1){
		res+=solve(sump);
		ans=min(ans,res);
		return;
	}
	for(int j=1;j<=n;j++){
		eg2[++idx].u=sump+1,eg2[idx].v=j,eg2[idx].w=c[t][j];
	}
	dfs(t+1,res+c[t][0],sump+1);
	idx-=n;
	dfs(t+1,res,sump);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>eg[i].u>>eg[i].v>>eg[i].w;
	}
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]==0)w0[i]=j;
		}
		if(c[i][0]!=0)flag=0;
	}
	sort(eg+1,eg+m+1,cmp);
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=eg[i].u,v=eg[i].v,w=eg[i].w;
		if(getf(u)!=getf(v)){
			f[getf(u)]=getf(v);
			eg2[++idx]=eg[i];
		//	cout<<eg[i].u<<eg[i].v<<eg[i].w<<"\n";
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				eg2[++idx].u=i+n,eg2[idx].v=j,eg2[idx].w=c[i][j];
			}
		}
	}
	//cout<<"?";
	if(k==0||flag){
		ans=solve(n+k);
		cout<<ans;
		return 0;
	}
	dfs(1,0,n);
	cout<<ans<<"\n";
	//cout<<tot;
	return 0;
}
