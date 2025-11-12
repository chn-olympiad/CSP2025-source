#include<bits/stdc++.h>
#define int long long
#define N 10100
#define M 3000005
using namespace std;
int s,f;
char ch;
inline int read() {
	s=0, f=1;
	do if(ch=='-') f=-1;
	while((ch=getchar())<48);
	do s=(s<<3)+(s<<1)+(ch^48);
	while((ch=getchar())>47);
	return s*f;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
struct Edge {
	int fr,to,val;
	inline bool operator < (const Edge &p) const {
		return val<p.val;
	}
} e[M];
int n,m,k,c[11],a[11][N],fa[N],p;
inline int ask(int x) {
	if(x==fa[x]) return x;
	return fa[x]=ask(fa[x]);
}
int flc,F,T,ans=2e9,now,aa,bb,vec[N],sz,dp[N];
inline int calc() { // 根据当前 fa 数组的状态，指定简单集合覆盖
	sz=0;
	int res=2e17,sum=0;
	for(int i=1; i<=n; i++) vec[++sz]=fa[i];
	sort(vec+1,vec+sz+1);
	flc=unique(vec+1,vec+sz+1)-vec-1;
	for(int i=1; i<=k; i++) {
		sum=0;
		for(int j=1; j<=flc; j++) {
			printf("%d ",a[i][vec[j]]);
			sum+=a[i][vec[j]];
		}
		puts("");
		res=min(res,sum+c[i]);
	}
	printf("\n%d %d\n",now,res);
	return now+res;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(), m=read(), k=read();
	if(n==1) {
		puts("0");
		return 0;
	}
	for(int i=1; i<=m; i++) {
		e[i].fr=read();
		e[i].to=read();
		e[i].val=read();
	}
	for(int i=1; i<=k; i++) {
		c[i]=read();
		for(int j=1; j<=n; j++)	a[i][j]=read();
	}
	// 将此时的题目想象成在最小生成树的过程中加入新的点来联通它们
	sort(e+1,e+m+1);
	for(int i=1; i<=n; i++) fa[i]=i;
//	ans=min(ans,calc());
	for(int i=1; i<=m; i++) {
		if(p==n-1) break;
		F=e[i].fr,T=e[i].to;
		aa=ask(F),bb=ask(T);
		if(aa==bb) continue;
		p++;
		fa[aa]=bb;
		now+=e[i].val;
		for(int j=1; j<=k; j++) a[j][bb]=min(a[j][bb],a[j][aa]);
//		ans=min(ans,calc());
	}
	write(now);
	return 0;
}