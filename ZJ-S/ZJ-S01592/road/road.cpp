#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
#define bug(a) cout<<" ( "<<#a<<" : "<<a<<" ) ";
#define bugln(a) cout<<" ( "<<#a<<" : "<<a<<" )\n";
#define bugg cout<<" --Debug ";
#define buggln cout<<" --Debug\n";
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define PII pair<int,int>
using namespace std;

const int M=1e4+10,N=2e6+10,K=11;

int n,m,k;
struct node{
	int u,v,w;
}e[N],f[K][M],tmp[N],tmp2[N];
int c[K];
int fa[M];
int mn=1e18;

int gf(int x){
	if(x==fa[x])return x;
	return fa[x]=gf(fa[x]);
}

void solve(int st){
	int idx=0,cnt=0,ans=0;
	For(i,1,k){
		if(st&(1<<(i-1))){
			For(j,1,n){
				tmp2[++idx]=f[i][j];
				cnt++;
			}
			ans+=c[i];
		}
	}
	For(i,1,n+cnt){
		fa[i]=i;
	}
	sort(tmp2+1,tmp2+idx+1,[](node q,node h){
		return q.w<h.w;
	});
	int i=1,j=1;
	For(k,1,idx+m){
//		bug(i)bug(j)bug(m)bugln(idx)
		if(j>idx||(i<=m&&e[i].w<=tmp2[j].w)){
			tmp[k]=e[i++];
		}else{
			tmp[k]=tmp2[j++];
		}
	}
//	bug(1)
//	For(i,1,idx+m){
//		printf("%lld ",tmp[i].w);
//	}buggln
	int tot=1;
	For(i,1,idx+m){
		if(tot==n+cnt){
			break;
		}
		int u=gf(tmp[i].u);
		int v=gf(tmp[i].v);
//		bug(u)bugln(v)
		if(u==v)continue;
		fa[u]=fa[v];
		ans+=tmp[i].w;
//		bug(ans)
		tot++;
	}
//	printf("%lld\n",ans);
	mn=min(mn,ans);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	bug(sizeof e)
	scanf("%lld%lld%lld",&n,&m,&k);
	For(i,1,n+k){
		fa[i]=i;
	}
	For(i,1,m){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,[](node q,node h){
		return q.w<h.w;
	});
	For(i,1,k){
		scanf("%lld",&c[i]);
		For(j,1,n){
			int w;scanf("%lld",&w);
			f[i][j]={n+i,j,w};
		}
	}
	For(i,0,(1<<k)-1){
		solve(i);
	}
	printf("%lld",mn);
	return 0;
}
//chzx_lfw AK IOI!!!!!

//Never notice me
//Never call my name with your voice!
//Let me forget everything
//Still moonlight shines on us
//...
//I'll end it all.
//And testify!!!!
