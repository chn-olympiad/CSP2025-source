#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7+10;
int n,m,k,fa[N],a[10][10010],tot,sum,num,cnt=1;
int zz(int x){
	if(fa[x]==x) return x;
	return fa[x]==zz(fa[x]);
}
struct node{
	int u,v,w;
}g[N];
bool cmp(node c,node d){
	return c.w<d.w;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>g[i].u>>g[i].v>>g[i].w,num++;
	for(int i=1,x;i<=k;i++) {
		cin>>a[i][0];
		for(int j=1,x;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				num++;
				g[num].u=j;
				g[num].v=k;
				g[num].w=a[i][j]+a[i][k];
			}
		}
	}
	sort(g+1,g+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(cnt==n) break;
		int fu=zz(g[i].u),fv=zz(g[i].v);
		if(fu==fv) continue;
		fa[fv]=fu;cnt++;
		tot+=g[i].w;
	}
	for(int i=1;i<=k;i++) tot+=a[i][0]; 
	cout<<tot<<"\n";
	return 0;
}