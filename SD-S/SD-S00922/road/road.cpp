#include <bits/stdc++.h>
#define ret return
#define mp make_pair
#define pb push_back
#define mid (l+r>>1)
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int N=1e4+10;
int val[11][N],f[N+10],tot=0;
struct E{int x,y,z;}e[N*100],w[N];
inline int find(int x){ret (x==f[x])?x:(f[x]=find(f[x]));}
vector<E> st[32768];
void fs(int n){
	int val=32767,cnt=0;
	for(int i=1;i<=n;i++)st[e[i].z&val].pb(e[i]);
	for(int i=0;i<=val;i++){for(auto j:st[i])e[++cnt]=j;st[i].clear();}cnt=0;
	for(int i=1;i<=n;i++)st[e[i].z>>15].pb(e[i]);
	for(int i=0;i<=val;i++){for(auto j:st[i])e[++cnt]=j;st[i].clear();}
}
long long kruskal(long long val){
	fs(tot);
	long long sum=0;
	for(int i=1;i<=tot&&sum<=val;i++){
		int x=e[i].x,y=e[i].y,fx=find(x),fy=find(y);
		if(fx==fy)continue;f[fx]=fy;sum+=e[i].z;
	}
	ret sum;
}
void solve(){
	int n=read(),m=read(),k=read();
	long long ans=0;for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){e[i].x=read();e[i].y=read();e[i].z=read();}fs(m);
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,fx=find(x),fy=find(y);
		if(fx==fy)continue;f[fx]=fy;w[++tot]=e[i];ans+=e[i].z;
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)val[i][j]=read();
	for(int i=0;i<(1<<k)-1;i++){
		for(int j=1;j<=n-1;j++)e[j]=w[j];
		tot=n-1;long long sum=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1)continue;
			for(int wwt=1;wwt<=n;wwt++)
			e[++tot]=E{j+n,wwt,val[j][wwt]};
			sum+=val[j][0];
		}
		for(int j=1;j<=n+k;j++)f[j]=j;
		ans=min(ans,sum+kruskal(ans-sum));
	}
	printf("%lld",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;while(t--)solve();ret 0;
}
