#include <bits/stdc++.h>
using namespace std;
const int N=2000010;
int n,m,k,uu,fa[N],vv,ww,cn_t,x,y,tj,bl,px,py;
long long ans;
struct nod1{
	int pp,va,edge1;
	bool operator<(const nod1 &mfmf)const{
		return va<mfmf.va;
	}
}cc[N*2];
void add1(int u,int v,int w){
	cc[++cn_t].va=w;
	cc[cn_t].edge1=v;
	cc[cn_t].pp=u;
	return ;
}
int fin(int mf){
	if(fa[mf]==mf) return mf;
	return fa[mf]=fin(fa[mf]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>uu>>vv>>ww;
		add1(uu,vv,ww);
		add1(vv,uu,ww);
	}
	sort(cc+1,cc+cn_t+1);
		for(int i=1;i<=n;++i) fa[i]=i;
		bl=1;
		while(tj<n-1){
			x=cc[bl].pp,y=cc[bl].edge1;
			px=fin(x);py=fin(y);
			if(px!=py){
				fa[px]=py;
				++tj;
				ans+=(long long)cc[bl].va; 
			}
			++bl;
		}
		cout<<ans;
	return 0;
}

