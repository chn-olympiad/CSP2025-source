#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
long long c[20],a[20][N],ans;
struct node{
	int u,v;
	long long w;
}e[2*M];
int fa[N];
int find(int a){
	if(fa[a]==a)return a;
	return fa[a]=find(fa[a]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void link(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	int num=n;
	for(int i=1;i<=m;i++){
		if(num<=1)break;
		int x=e[i].u,y=e[i].v;
		int fx=find(x),fy=find(y);
//		cout<<e[i].w<<' '<<fx<<' '<<fy<<'\n';
		if(fx!=fy){
			link(x,y);
			num--;
			ans+=e[i].w;
//			cout<<ans<<'\n';
		}
	}
	cout<<ans;
	return 0;
}