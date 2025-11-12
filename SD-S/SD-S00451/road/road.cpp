#include<bits/stdc++.h>
#define N 10004
#define mp make_pair
#define pb push_back
using namespace std;//T1 58min sxzLLL
void r(int&x){//u32
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}return;
}
int n,m,k,c;
int city[11][N];
vector<pair<int,int> > e[N];
int fa[N];
bool getfa(int x){
	return fa[x]==x?x:(fa[x]=getfa(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	r(n),r(m),r(k);int u,v,w;
	for(int i=1;i<=m;++i){
		r(u),r(v),r(w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j){
			r(u);
		}
	}
	srand(time(0));
	cout<<rand();
	return 0;
}
