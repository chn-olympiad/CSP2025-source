#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int M=1e6,N=1e4;
struct edge{
	int u,v,w;
}a[M+10];
int b[N+10][20];
int c[20];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int pre[N+10];
int cha(int a){
	if(pre[a]!=a) return pre[a]=cha(pre[a]);
	return pre[a];
}
void bin(int a,int b){
	int x=cha(a),y=cha(b);
	if(x!=y) pre[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) 
		cin>>b[j][i];
	}
	for(int i=1;i<=n;++i) pre[i]=i;
	sort(a+1,a+1+m,cmp);
	long long int ans=0;
	for(int i=1;i<=n;++i){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int x=cha(u),y=cha(v);
		if(x!=y){
			bin(x,y);
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 5 2
1 2 2
1 3 5
1 4 1
4 3 4
3 2 3
1 1 8 2 4
100 1 3 2 4
*/
