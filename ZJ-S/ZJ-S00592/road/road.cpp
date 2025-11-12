#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,vis[10011],fat[10011],ans,c[11];
struct edge{
	int u,v,w;
}e[1100001];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa(int x){
	if(fat[x]==x)return x;
	return fat[x]=fa(fat[x]);
}
void merge(int x,int y){
	x=fa(x);
	y=fa(y);
	fat[y]=x;
}
int A(int t){
	for(int i=1;i<=n+t;i++)fat[i]=i;
	sort(e+1,e+m+t*n+1,cmp);
	int now=1,ans=0;
	for(int i=1;now<n+t;i++){
		if(fa(e[i].u)==fa(e[i].v))continue;
//		cout<<e[i].v<<" "<<vis[e[i].v]<<endl;
		if(!vis[e[i].v])continue;
		now++;
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
	}
//	cerr<<ans<<endl;
	return ans;
}
int dfs(int d,int t,int now){
	if(d==k)return A(t)+now;
	int ans=dfs(d+1,t,now);
	vis[n+d+1]=1;
	ans=min(ans,dfs(d+1,t+1,now+c[d+1]));
	vis[n+d+1]=0;
	return ans;
}
void B(){
	cout<<dfs(0,0,0)<<endl;
}
void C(){
	for(int i=1;i<=k;i++){
		vis[n+i]=1;
	}
	cout<<A(k)<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool flg=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flg=0;
		bool flg2=0;
		for(int j=1;j<=n;j++){
			int b=0;
			cin>>b;
			e[m+j+n*(i-1)].w=b;
			e[m+j+n*(i-1)].u=j;
			e[m+j+n*(i-1)].v=n+i;
			if(b==0)flg2=1;
		}
		flg&=flg2;
	}
	for(int i=1;i<=n;i++)vis[i]=1;
	if(k==0)cout<<A(0)<<endl;
	else if(flg)C();
	else B();
	return 0;
}
//11.1 17:47
//code by K.S.
//want 40 pts.
