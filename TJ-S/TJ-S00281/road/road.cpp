#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5,M = 1e6 + 5;
struct node{
	int from,to,wei;
}edg[M]; 
int n,m,k,c[15],a[15][N],ans,bian,f,b;
int fa[N];
bool v[15];
bool cmp(node x,node y){
	return x.wei<y.wei;
}
int find(int num){
	if(fa[num]!=num){
		fa[num]=find(fa[num]);
	}
	return fa[num];
}
bool check(int u,int v){
	return find(u)==find(v);
}
void unions(int u,int v){
	fa[u]=v;
}
void K(){
	sort(edg+1,edg+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(!check(edg[i].from,edg[i].to)){
			unions(edg[i].from,edg[i].to);
			ans+=edg[i].wei;
			if(++bian==n-1) break;
		}
	}
	cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edg[i].from>>edg[i].to>>edg[i].wei;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) f=1;
		}
		if(f==0) b=1;
		f=0;
	}
	if(b==1) cout<<0<<'\n';
	else K();
	return 0;
}

