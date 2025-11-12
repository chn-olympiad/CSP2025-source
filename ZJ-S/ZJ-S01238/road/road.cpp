#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10004;
int n,m,k,f[N];
struct node{
	int u,v;
	ll w;
}l[1000006];
int a[12][N],c[12];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void solve1(){
	ll ans=0;
	sort(l+1,l+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=l[i].u,v=l[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;
			ans+=l[i].w;
		}
	}
	cout<<ans;
}
void solve2(){
	int ans=0;
	sort(l+1,l+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=l[i].u,v=l[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;
			ans+=l[i].w;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>l[i].u>>l[i].v>>l[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0)solve1();
	else solve1();
	return 0;
} 
