#include<bits/stdc++.h>
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
#define ff(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
using namespace std;
const int N=1e3+10,M=1e4+10,K=11;
int n,m,k;
int flagA;
int ans;
struct edge{
	int u,v,w;
}e[M];
int c[K];
int a[K][N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ff("road");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j])flagA=1;
		}
	}
	if(!flagA){
		cout<<0;
	}
	else {
		int res=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<n;i++){
			res+=e[i].w;
		}
		cout<<res;
	}
	return 0;
}


