#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
int fa[N],vis[N];
long long ans=0;
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
struct node{
	int u,v,w,pos;
}e[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int a[12][N];
int c[12],sum,viss[12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
    for(int i=1;i<=m;i++)
    cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
    cin>>c[i];
    if(c[i]==0) sum++;
    for(int j=1;j<=n;j++)
    cin>>a[i][j];
}

if(k==0) {
    sort(e+1,e+1+m,cmp);	
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		else fa[x]=y,cnt++,ans+=e[i].w;
		if(cnt==n-1) break;
	}
	cout<<ans;
}
else if(sum==k){
	int mm=m;
	for(int i=1;i<=k;i++)
	for(int j=1;j<=n;j++)
    {
    if(a[i][j]==0){
    for(int p=1;p<=n;p++)
    if(p!=j){
	e[++mm].u=j,e[mm].v=p,e[mm].w=a[i][p],e[mm].pos=i;}
	}
}
    sort(e+1,e+1+mm,cmp);	
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		else fa[x]=y,cnt++,ans+=e[i].w;
		if(cnt==n-1) break;
	}
	cout<<ans;
}
	return 0;
} 
