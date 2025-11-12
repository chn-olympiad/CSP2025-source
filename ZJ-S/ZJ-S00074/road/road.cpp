#include<bits/stdc++.h>
using namespace std;
int m,n,k,sum=INT_MAX,f[100010],a[11][100010],f2[100010];
int find(int x){
	if(f2[x]==x){
		return x;
	}
	return f2[x]=find(f2[x]);
}
struct f1{
	int u,v,w;
}q[100010];
bool cmp(f1 x,f1 y){
	return x.w>y.w;
}
int dfs0(f1 q1[]){
	int ans=0;
	for(int i=1;i<=m;i++){
		f[i]=i;
	}
	sort(q1+1,q1+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(q1[i].u)!=find(q1[i].v)){
			ans+=q1[i].w;
			f2[find(q1[i].u)]=find(q1[i].v);
		}
	}
	return ans;
}
void dfs(int u1,int sum1){
	if(u1==k+1){
		sum=min(sum,dfs0(q)+sum1);
		return;
	}
	dfs(u1+1,sum1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			q[++m].u=i;q[m].v=j;q[m].w=a[u1][i]+a[u1][j];
		}
	}
	dfs(u1+1,sum1+f[u1]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	cout<<sum;
}
