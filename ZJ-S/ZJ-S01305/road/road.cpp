#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qd(){
	char t;
	ll ans=0;
	int fh=1;
	t=getchar();
//	cout<<t;
	if(t=='-'){
		fh=-1;
		t=getchar();
	}
//	cout<<t;
	while(t>='0' && t<='9'){
		ans*=10;
		ans+=t-'0';
		t=getchar();
//		cout<<t;
	}
	return ans*fh;
}
const int N=1e4+15;
ll n,m,k;
struct node{
	ll u,v,w;
};
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
int fa[N];
int bcj(int x){
	if(fa[x]==x) return x;
	fa[x]=bcj(fa[x]);
	return fa[x];
}
ll solve1(){
	vector<node> rd(m+1);
	for(int i=1;i<=m;i++){
		rd[i].u=qd();rd[i].v=qd();rd[i].w=qd();
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(rd.begin(),rd.end(),cmp);
	ll ans=0;
	for(int i=1;i<=n;i++){
		int xi=bcj(rd[i].u),yi=bcj(rd[i].v);
		if(xi!=yi){
			fa[xi]=yi;
			ans+=rd[i].w;
		}
	}
	return ans;
}
ll kx[11][N];
ll sve(vector<node> rd,ll nn,ll qs){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(rd.begin(),rd.begin()+nn+1,cmp);
	ll ans=0;
	for(int i=1;i<=nn;i++){
		int xi=bcj(rd[i].u),yi=bcj(rd[i].v);
		if(xi!=yi){
			fa[xi]=yi;
			ans+=rd[i].w;
		}
	}
	return ans+qs;
}
ll dfs(int nx,vector<node> rd,ll qs,ll rdi){
	if(nx>k){
		return sve(rd,rdi,qs);
	}
	ll ans=dfs(nx+1,rd,qs,rdi);
	for(int i=1;i<=n;i++){
		rd[rdi+i]={nx+n,i,kx[nx][i]};
	}
	return min(ans,dfs(nx+1,rd,qs+kx[nx][0],rdi+n));
}
ll solve2(){
	vector<node> rd(m+n*k+1);
	for(int i=1;i<=m;i++){
		rd[i].u=qd();rd[i].v=qd();rd[i].w=qd();
	}
	for(int i=1;i<=k;i++){
		kx[i][0]=qd();
		for(int j=1;j<=n;j++){
			kx[i][j]=qd();
		}
	}
	return dfs(1,rd,0,m);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=qd();m=qd();k=qd();
	if(k==0){
		printf("%lld",solve1());
	}
	else{
		printf("%lld",solve2());
	}
	return 0;
}

