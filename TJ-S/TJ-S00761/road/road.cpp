#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e5+5;
int dis[N];
int fa[N];
int c[15][N];
struct node{
	int x,y,z;
};
node e[N];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){
	return (x==fa[x]?x:find(fa[x]));
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	for(int j=1;j<=n;j++){
		cin>>c[j][1];
		for(int i=2;i<=n;i++){
			cin>>c[j][i];
		}
	}
	
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++){
		int a=e[i].x,b=e[i].y,c=e[i].z;
		if(find(a)!=find(b)){
			merge(a,b);
			ans+=c;
		}
	}
	cout<<ans<<endl;
	return 0;
}
