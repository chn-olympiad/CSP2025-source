#include <bits/stdc++.h>
using namespace std;
#define int long long
int k;
struct node{
	int u;
	int v;
	int w;
};
int n,m;
node e[1000005];
int spnode[12][10005];
int spcost[12];
void scan(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>spcost[i];
		for(int j=1;j<=n;j++){
			cin>>spnode[i][j];
		}
	} 
	return ;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[10005];
int find(int x){
	if(f[x]==x){
		return f[x];
	}
	f[x]=find(f[x]);
	return f[x];
}
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	return ;
}
int ans=0;
void zxscs(){
	int cnt=0;
	int id=1;
	while(cnt<n-1){
		if(id>m){
			ans=-1;
			return;
		}
		node t=e[id];
		id++;
		int u=t.u;int v=t.v;int w=t.w;
		if(find(u)==find(v)){
			continue;
		}
		f[find(u)]=v;
		ans+=w;
		cnt++;
		
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scan();
	init();
	sort(e+1,e+m+1,cmp);

	zxscs();
	cout<<ans<<endl;
	return 0;
}
/*


5 7 0
1 3 1
3 5 8
1 5 2
1 2 11
4 5 4
1 4 3
2 3 6


12

*/
