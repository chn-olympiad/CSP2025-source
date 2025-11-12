#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+1e5+10,N=1e4+10;
int n,m,k,fa[N];
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=(find(fa[x]));
}
void kruskal(){
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		int x=find(u);
		int y=find(v);
		if(x!=y){
			fa[x]=fa[y];
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<"\n";
}
signed main(){
	   ios::sync_with_stdio(0);
	   cin.tie(0),cout.tie(0);
	   freopen("road.in","r",stdin);
	   freopen("road.out","w",stdout);
      cin>>n>>m>>k;
      for(int i=1;i<=m;i++){
      	int a,b,c;
      	cin>>a>>b>>c;
      	e[i].u=a,e[i].v=b,e[i].w=c;
	  }
	  for(int i=1;i<=k;i++){
	  	int p;
	  	cin>>p;
	  	for(int j=1;j<=n;j++){
	  		int q;
	  		cin>>q;	
		  }
	  }
	  kruskal();
	   return 0;
 }
 /*
 4 4 2
 1 2 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
13
*/

