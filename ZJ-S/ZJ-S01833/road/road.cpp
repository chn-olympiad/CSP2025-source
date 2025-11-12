#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0x3f3f3f3f;
int n,m,k;
int el[11];
bool vis[11];
struct edge{
	int u,v,w;
	int tag;
}a[1101000];
int fa[10100];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int dx=find(x),dy=find(y);
	fa[dx]=fa[dy];
}
int solve(){
	int res=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==m-1) break;
		
		if(vis[a[i].tag]){
			//cout<<a[i].tag<<endl;
			if(find(a[i].u)!=find(a[i].v)){
				merge(a[i].u,a[i].v);
				res+=a[i].w;
			}
		}
	}
	return res;
}
int solve2(){
	int res=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==m-1) break;
		
			//cout<<a[i].tag<<endl;
			if(find(a[i].u)!=find(a[i].v)){
				merge(a[i].u,a[i].v);
				res+=a[i].w;
			}
	}
	return res;
}
void dfs(int dep,int sum){
	if(dep>k) return;
	if(sum>=ans) return;
	for(int i=1;i<=n;i++) fa[i]=i;
	int r1=solve();
	if(r1>=ans) return;
	else ans=r1+sum;
	vis[dep]=true;
	n++;
	for(int i=1;i<=n;i++) fa[i]=i;
	int r2=solve();
	if(r2+el[dep]<r1){
		ans=r2+sum+el[dep];
		dfs(dep+1,sum+el[dep]);
	}
	vis[dep]=false;
	n--;
	dfs(dep+1,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].tag=0;
	}
	bool fl=true;
	vis[0]=true;
	for(int i=1;i<=k;i++){
		cin>>el[i];
		if(el[i]!=0) fl=false; 
		for(int j=1;j<=n;j++){
			a[++m].u=i+n;
			a[m].v=j;
			cin>>a[m].w;
			a[m].tag=i;
		}
	}
	sort(a+1,a+m+1,cmp);
	if(fl==true){
		n+=k;
		for(int i=1;i<=n;i++) fa[i]=i;
		cout<<solve2();
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

