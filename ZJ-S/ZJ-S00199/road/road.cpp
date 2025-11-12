#include<bits/stdc++.h>
using namespace std;
#define for1(i,a,b) for(int i=(a);i<=(b);i++)
#define for2(i,a,b) for(int i=(a);i<(b);i++)
#define for3(i,a,b) for(int i=(a);i>=(b);i--)
#define for4(i,a) for(auto &i:(a))
#define puba push_back
#define pii pair<int,int>
#define ll long long
#define mem(a,b) memset((a),(b),sizeof((a)))
#define int long long
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,x,ans,minn=1e16,cnt1,cnt2,c[K];
int fa[N+K],siz[N+K];
void clear(){
	for1(i,1,n+k) fa[i]=i,siz[i]=1;
	ans=0;
}
int get(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=get(fa[x]);
}
void mrg(int x,int y,int z){
	x=get(x),y=get(y);
	if(x!=y){
		if(siz[x]>siz[y]) swap(x,y);
		siz[y]+=siz[x];
		fa[x]=y;
		ans+=z;
	}
}
struct edge{
	int u,to,w;
}e[M],e1[N*K],e2[N*K],e3[K][N],e4[N*K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for1(i,1,m){
		cin>>e[i].u>>e[i].to>>e[i].w;
	}
	for2(i,0,k){
		cin>>c[i];
		for1(j,1,n){
			cin>>x;
			e3[i][j]={j,i+1+n,x};
		}
		sort(e3[i]+1,e3[i]+n+1,cmp);
	}
	sort(e+1,e+m+1,cmp);
	clear();
	for1(i,1,m){
		int x=get(e[i].u),y=get(e[i].to);
		if(x!=y){
			fa[x]=y;
			ans+=e[i].w;
			e1[++cnt1]=e[i];
		}
	}
	minn=ans;
	for2(i,1,1<<k){
		clear();
		for1(j,1,cnt1) e2[j]=e1[j];
		cnt2=cnt1;
		for2(j,0,k){
			if((i>>j)&1){
				ans+=c[j];
				int i1=1,j1=1,res=0;
				while(i1<=cnt2&&j1<=n){
					if(e2[i1].w<e3[j][j1].w) e4[++res]=e2[i1],i1++;
					else e4[++res]=e3[j][j1],j1++;
				}
				while(i1<=cnt2) e4[++res]=e2[i1],i1++;
				while(j1<=n) e4[++res]=e3[j][j1],j1++;
				swap(res,cnt2);
				for1(ii,1,cnt2) e2[ii]=e4[ii];
			}
		}
		for1(j,1,cnt2){
			int x=get(e2[j].u),y=get(e2[j].to);
			if(x!=y){
				fa[x]=y;
				ans+=e2[j].w;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	
	return 0;
}