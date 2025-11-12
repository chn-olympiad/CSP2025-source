#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
#define pii pair<int,int>
#include<vector>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
int fa[N];
ll ans;
ll p[15][N];
struct node{
	int x,y;
	ll w;
}E[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int Find(int a){
	if(fa[a]==a){
		return	fa[a];
	}
	 fa[a]=Find(fa[a]);
	 return fa[a];
} 
int c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>E[i].x>>E[i].y>>E[i].w;
	}
	
	int c;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
		}
//		for(int j=1;j<=n;j++){
//			for(int k=j+1;k<=n;k++){
//				E[p].x=j,E[]
//			}
//		}
	}
	for(int i=1;i<=m;i++){
		int a=E[i].x,b=E[i].y;
		for(int j=1;j<=k;j++){
			E[i].w=min(E[i].w,p[j][a]+p[j][b]);
		}
	}
	sort(E+1,E+1+m,cmp);
	//int pmp=1;
	for(int i=1;i<=m;i++){
		int a=E[i].x,b=E[i].y;
		ll c=E[i].w;
		if(Find(a)!=Find(b)){
			fa[Find(a)]=Find(b);
			fa[Find(b)]=Find(a);
			ans+=c;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
