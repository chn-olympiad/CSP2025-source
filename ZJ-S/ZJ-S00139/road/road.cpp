#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace l_mid_r{
	const int N=1e4+20,M=2e6+5,K=15,inf=0x3f3f3f3f3f3f3f3f;
	int n,m,k,cost[N],ans=inf,fa[N];
	bool cs[K];
	struct node{
		int s,t,w;
	}e[M];
	inline int rd(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int fd(int x){
		if(fa[x]==x) return x;
		return fa[x]=fd(fa[x]);
	}
	void merge(int u,int v){
		fa[fd(u)]=fd(v);
	}
	int solve(){
		int sum=n,cnt=0;
		for(int i=1;i<=k;i++) if(cs[i]) sum++;
		//~ for(int i=1;i<=k;i++) if(cs[i]) printf("%lld\n",i);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1,j=1;i<=m&&j<sum;i++){
			node u=e[i];
			
			if(u.s>n&&(!cs[u.s-n])) continue;
			//~ printf("%lld %lld\n",u.s,u.t);
			if(fd(u.s)==fd(u.t)) continue;
			
			cnt+=u.w,j++,merge(u.s,u.t);
		}
		//~ printf("%lld\n",cnt);
		return cnt;
	}
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		n=rd(),m=rd(),k=rd();
		for(int i=1;i<=m;i++){
			int u=rd(),v=rd(),w=rd();
			e[i]={u,v,w};
		}
		for(int i=1;i<=k;i++){
			cost[i]=rd();
			for(int j=1;j<=n;j++){
				e[++m]={n+i,j,rd()};
			}
		}
		sort(e+1,e+m+1,[&](const node &u,const node &v){return u.w<v.w;});
		for(int i=0;i<(1<<k);i++){
			int cnt=0;
			memset(cs,0,sizeof cs);
			for(int j=0;j<k;j++){
				if((i>>j)&1) cnt+=cost[j+1],cs[j+1]=1;
			}
			cnt+=solve();
			ans=min(ans,cnt);
		}
		printf("%lld\n",ans);
		return 0;
	}
}
signed main(){return l_mid_r::main();}
