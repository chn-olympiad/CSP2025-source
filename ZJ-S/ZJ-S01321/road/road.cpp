#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int n,m,k,a[10005],fa[10005];
long long ans;
struct E{
	int u,v,w;
}e[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(E a,E b){
	a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freoprn("road.out"."w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+m+1,cmp);
		int sum=0;
		for(int i=1;i<=m;i++){
			if(find(e[i].u)==find(e[i].v)) continue;
			else{
				fa[e[i].u]=e[i].v;
				ans+=e[i].w;
				sum++;
			}
			if(sum==n-1) break;
		}
	}
	else{
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
		}
		for(int i=1;i<=k;i++){
			for(int i=0;i<=n;i++){
				int a;
				cin>>a;
			}
		}
	}
	cout<<ans;
	return 0;
}

