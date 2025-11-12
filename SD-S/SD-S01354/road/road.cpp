#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mN=1e4+5,N=2e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
}
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
int fa[mN];
inline void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
	return;
}
inline int find(int x){
	return (fa[x]==x?x:(fa[x]=find(fa[x])));
}
inline void update(int u,int v){
	u=find(u);v=find(v);
	fa[v]=u;
	return;
}
struct node{
	int u,v,w;
}a[N],p[N];
inline bool cmp(node x,node y){return x.w<y.w;}
int f[11][mN],cnt;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=qr,m=qr,k=qr;
	for(int i=1;i<=m;i++) p[i]={qr,qr,qr};
	sort(p+1,p+m+1,cmp);
	init(n);
	for(int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v,w=p[i].w;
		if(find(u)==find(v)) continue;
		a[++cnt]=p[i];
		update(u,v);
	}
	m=n-1;
	for(int i=1;i<=m;i++) p[i]=a[i];
	for(int i=1;i<=k;i++){
		f[i][0]=qr;
		for(int j=1;j<=n;j++) f[i][j]=qr;
	}
	int minn=1e18; 
	for(int s=0;s<(1<<k);s++){
		init(n*(k+1));
		int ans=0;
		for(int i=1;i<=m;i++) a[i]=p[i];
		for(int i=1;i<=k;i++){
			if(s&(1<<(i-1))){
				ans+=f[i][0];
				for(int j=1;j<=n;j++){
					a[m+n*(i-1)+j].u=n+i;
					a[m+n*(i-1)+j].v=j;
					a[m+n*(i-1)+j].w=f[i][j];
				}
			}
			else for(int j=1;j<=n;j++){
				a[m+n*(i-1)+j].u=n+i;
				a[m+n*(i-1)+j].v=j;
				a[m+n*(i-1)+j].w=1e18;
			}
		}
		sort(a+1,a+m+n*k+1,cmp);
		for(int i=1;i<=m+n*k;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			if(u>n&&w==1e18) continue;
			if(find(u)==find(v)) continue;
			update(u,v);
			ans+=w;
		}
		minn=min(minn,ans);
	}
	qw(minn);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
