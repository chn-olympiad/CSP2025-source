//kruskal除了A性质应该卡不掉吧/ll/ll/ll 
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int n,m,k,c[15],a[15][10005],fa[10015],ans=0x3f3f3f3f3f3f3f3f,tot,tot2,res,sum,u,v,p;
bool flag[15];
struct edge{
	int u,v,w;
	bool operator<(edge x)const{
		return w<x.w; 
	}
}e[1010005],e1[1000005],e2[10005];
int find(int u){
	if(fa[u]==u)
		return u;
	return fa[u]=find(fa[u]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m)
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	sort(e1+1,e1+m+1);
	rep(i,1,k){
		flag[i]=1;
		cin>>c[i];
		if(c[i])
			flag[i]=0;
		bool flag2=0;
		rep(j,1,n){
			cin>>a[i][j];
			if(!a[i][j])
				flag2=1;
		}
		flag[i]&=flag2;
	}
	rop(i,0,1<<k){
		sum=n-1;
		res=tot=tot2=0;
		rep(j,1,k){
			if((i>>j-1)&1){
				sum++;
				res+=c[j];
				rep(l,1,n)
					e2[++tot2]={l,j+n,a[j][l]};
			}
			else if(flag[j])
				goto loop;
		}
		if(res>ans)
			break;
		sort(e2+1,e2+tot2+1);
		p=1;
		rep(j,1,m){
			while(e2[p].w<=e1[j].w&&p<=tot2){
				e[++tot]=e2[p];
				p++;
			}
			e[++tot]=e1[j];
		}
		while(p<=tot2){
			e[++tot]=e2[p];
			p++;
		}
		rep(j,1,n+k)
			fa[j]=j;
		rep(j,1,tot){
			if(!sum)
				break;
			u=find(e[j].u);
			v=find(e[j].v);
			if(u==v)
				continue;
			sum--;
			fa[v]=u;
			res+=e[j].w;
			if(res>ans)
				break;
		}
		ans=min(ans,res);
		loop:;
	}
	cout<<ans;
	return 0;
}
/*
100
*/

