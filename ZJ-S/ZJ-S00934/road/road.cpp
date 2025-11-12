#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=1e6+10;
int head[N],sum1,sum2,taen,n,m,k,f[N],a[N],ans,val[20][N],tt,tot,taeeen;
struct node{int x,y,val;}fe[M],e[N],ee[M+12*N];
bool cmp(node x,node y){return x.val<y.val;}
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int fa(int x){return (f[x]==x?x:f[x]=fa(f[x]));}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++) fe[i].x=read(),fe[i].y=read(),fe[i].val=read();
	for (int i=1;i<=k;i++){
		a[i]=read();
		for (int j=1;j<=n;j++) val[i][j]=read();
	}
	sort(fe+1,fe+m+1,cmp);taen=0;
	for (int i=1;i<=m;i++){
		int fx=fa(fe[i].x),fy=fa(fe[i].y);
		if (fx==fy) continue;
		ans+=fe[i].val;f[fx]=fy;
		e[++taen]=fe[i];
		if (taen==n-1) break;
	}
	int mi=ans;
	if (k==0){printf("%lld\n",ans);return 0;}
	for (int i=0;i<(1<<k);i++){
		tt=m;tot=n;ans=0;taeeen=0;
		for (int j=1;j<=tt;j++) ee[j]=fe[j];
		for (int j=1,ii=i;j<=k;j++,ii>>=1)
			if (ii&1){
				tot++;ans+=a[j];
				for (int l=1;l<=n;l++) ee[++tt].x=l,ee[tt].y=j+n,ee[tt].val=val[j][l];
			}
		sort(ee+1,ee+tt+1,cmp);
		for (int j=1;j<=tot;j++) f[j]=j;
		for (int j=1;j<=tt;j++){
			int fx=fa(ee[j].x),fy=fa(ee[j].y);
			if (fx==fy) continue;
			ans+=ee[j].val;f[fx]=fy;taeeen++;
			if (taeeen==tot-1){mi=min(mi,ans);break;}
		}
	}
	printf("%lld\n",mi);
	return 0;
}

