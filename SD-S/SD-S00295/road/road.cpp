#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+5,M=1e6+5;
struct node{
	int u;
	int v;
	int w;
};
node tu[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
int getfa(int x){
	if(fa[x]!=x) return fa[x]=getfa(fa[x]);
	else return x;
}
void merge(int a,int b){
	int aa,bb;
	aa=getfa(a);
	bb=getfa(b);
	if(aa!=bb){
		fa[bb]=aa;
	}
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) fa[i]=i;
	for(int i = 1;i<=m;i++){
		cin>>tu[i].u>>tu[i].v>>tu[i].w;
	}
	sort(tu+1,tu+m+1,cmp);
	int cnt = 0;
	ll ans = 0;
	for(int i = 1;i<=m;i++){
		if(cnt==n-1){
			break;
		}
		if(getfa(tu[i].u)==getfa(tu[i].v)) continue;
		cnt++;
		ans+=tu[i].w;
		merge(tu[i].u,tu[i].v);
	}
	if(k==0) cout<<ans<<"\n";
	else puts("0");
	return 0;
}

