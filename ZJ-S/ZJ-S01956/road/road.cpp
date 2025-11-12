#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;

struct N{
	int x,w,c,f;
};
struct Nn{
	int x,w;
};
vector<N> t[10005][15];
int x[1000005],y[1000005],w[1000005];
int a[10005];
int vis[10005][15];
int C[15];
int F[10005];
ll in=LLONG_MAX;
void fs(int x,ll w,int c,int f[],int nw[],int s,int p){
//	cout<<x<<" "<<c<<" "<<p<<" "<<w<<" "<<s<<"\n";
	if(s==n){
		in=min(in,w);
//		cout<<"!\n";
		return;
	}
	if(vis[x][c]) return;
	vis[x][c]=1;
	if(x<=k){
		if(f[x]==0){
			f[x]=1;
			fs(x,w+C[x],x,f,nw,s,x);
			f[x]=0;
		}else{
			fs(x,w,x,f,nw,s,x);
		}
	}
	for(auto to:t[x][c]){
		if(to.x==p) continue;
		if(nw[to.x]==0){
			nw[to.x]=1;
			fs(to.x,w+to.w,c,f,nw,s+1,x);
			nw[to.x]=0;
		}else{
			fs(to.x,w+to.w,c,f,nw,s,x);
		}
	}
	vis[x][c]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		t[x[i]][0].push_back({y[i],w[i],0,0});
		t[y[i]][0].push_back({x[i],w[i],0,0});
	}
//	cout<<"!";
	for(int i=1;i<=k;i++){
//		cin>>C[i];
		scanf("%d",&C[i]);
		for(int j=1;j<=n;j++){
//			cin>>a[j];
			scanf("%d",&a[j]);
			t[i][i].push_back({j,a[j],i,0});
			t[j][i].push_back({i,a[j],i,0});
		}
		for(int j=1;j<=m;j++){
			t[x[j]][i].push_back({y[j],w[j],i,0});
			t[y[j]][i].push_back({x[j],w[j],i,0});
		}
		for(int j=0;j<=k;j++){
			t[i][j].push_back({i,C[i],i,0});
			t[i][i].push_back({i,C[i],j,0});
		}
	}
//	cout<<"!";
	int xxf[15]={0},xxnw[10005]={0,1,0};
	fs(1,0,0,xxf,xxnw,1,-1);
	cout<<in;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
