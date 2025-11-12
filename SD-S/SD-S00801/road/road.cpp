#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct Node{
	int u,v,w;
}a[M];
int fa[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void unity(int a,int b){
	fa[find(a)]=find(b);
}
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int n,m,k,ans,c[114];
int kruskal(){
	sort(a+1,a+m+1,cmp);
	int visnode=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v))
		continue;
		unity(a[i].u,a[i].v);
		ans+=a[i].w;
		visnode++;
		if(visnode==n-1)
		break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	while(k--){
		int s; cin>>s;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				a[++m].u=i;
				a[m].v=j;
				a[m].w=c[i]+c[j]+s;
			}
		}
	}
	ans=kruskal();
	cout<<ans;
	return 0;
}

