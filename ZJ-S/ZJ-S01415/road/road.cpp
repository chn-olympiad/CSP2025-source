#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10105,maxm=1000005;
int n,m,k,len,fa[maxn],c[11];
bool vis[11];
struct edge{
	int x,y,z;
	bool operator < (const edge b) const {return z<b.z;}
}e[maxm],L[maxn*12],nowe[maxn*12];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace dhcio;
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].z=read();
	sort(e+1,e+1+m);
	for(int i=1;i<=m&&len!=n-1;i++){
		int fx=getfa(e[i].x),fy=getfa(e[i].y);
		if(fx==fy) continue;
		L[++len]=e[i];fa[fx]=fy;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			L[++len]=(edge){n+i,j,x};
		}
	}
	sort(L+1,L+1+len);
	LL ans=1ll<<60;
	for(int s=0;s<1<<k;s++){
		LL nowv=0;int Len=0,nown=n;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++)
		  if(s&(1<<i-1)) vis[i]=1,nowv+=c[i],nown++;else vis[i]=0;
		for(int i=1;i<=len;i++)
			if(L[i].x<=n||vis[L[i].x-n]) nowe[++Len]=L[i];
		int tot=0;
		for(int i=1;i<=Len&&tot!=nown-1;i++){
			int fx=getfa(nowe[i].x),fy=getfa(nowe[i].y);
			if(fx==fy) continue;
			nowv+=nowe[i].z;tot++;fa[fx]=fy;
		}
		ans=min(ans,nowv);
	}
	printf("%lld\n",ans);
	return 0;
}
