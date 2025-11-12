#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k,ans,ans1,cnt,tmp;
int fa[N];
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=N;i++) fa[i]=i;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y) return ;
	fa[x]=y;
}
void kruskal(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(get(a[i].u)==get(a[i].v)) continue ;
		merge(a[i].u,a[i].v);
		ans+=a[i].w,cnt++;
		if(cnt==n-1) return ;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	init();
	kruskal();
	ans1=ans;ans=0;
	if(k){
		cin>>tmp;
		for(int i=1;i<=k;i++)
			cin>>a[m+i].u>>a[m+i].v>>a[m+i].w;
		m+=k*n,n+=k;
	}
	kruskal();
	cout<<min(ans,ans1);
	return 0;
}
