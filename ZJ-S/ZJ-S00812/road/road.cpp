#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7+100;
int n,m,k;
int fa[100005];
struct node{
	int u,v,w;
}a[N];
int getf(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=getf(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int sum=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		for(int j=1,x;j<=n+1;j++)cin>>x;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=getf(a[i].u),y=getf(a[i].v);
		if(x==y)continue;
		fa[x]=y;
		sum+=a[i].w;
	}
	cout<<sum;
	return 0;
}