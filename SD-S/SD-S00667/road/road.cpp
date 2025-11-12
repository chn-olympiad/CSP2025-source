#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1ll)+(x<<3ll)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int const N=2e4+15,M=1e6+25;
int n,m,ans,cnt,k;
struct node {
	int u,v,w;
} a[M],b[M],cv[N];
int f[N],mei[15],c[15],cc[15][N];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int getf(int x) {
	if(x==f[x])  return f[x];
	return f[x]=getf(f[x]);
}
void dfs(int u) {
	if(u==k+1) {
		int num=n-1;
		int res=0;
		int qaq=0;
		for(int i=1; i<=k; i++) {
			if(mei[i]==1) {
				qaq++;
				for(int j=1; j<=n; j++) {
					num++;
					b[num].u=i+n;
					b[num].v=j;
					b[num].w=cc[i][j];
				}
				res+=c[i];
			}
		}
		cnt=0;
		for(int i=1; i<n; i++)  b[i]=cv[i];
		sort(b+1,b+1+num,cmp);
		for(int i=1; i<=n+k+5; i++)  f[i]=i;
		for(int i=1; i<=num; i++) {
			int x=b[i].u,y=b[i].v,w=b[i].w;
			int nx=getf(x),ny=getf(y);
			if(nx==ny)  continue;
			res+=w;
			f[nx]=ny;
			cnt++;
			if(cnt==n+qaq-1) {
				ans=min(ans,res);
				return;
			}
		}
		return;
	}
	mei[u]=1;
	dfs(u+1);
	mei[u]=0;
	dfs(u+1);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	cnt=0;
	for(int i=1; i<=m; i++) {
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	for(int i=1; i<=k; i++) {
		c[i]=read();
		for(int j=1; j<=n; j++) {
			cc[i][j]=read();
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=n+k+15; i++)  f[i]=i;
	for(int i=1; i<=m; i++) {
		int x=a[i].u,y=a[i].v,w=a[i].w;
		int nx=getf(x),ny=getf(y);
		if(nx==ny)  continue;
		ans+=w;
		f[nx]=ny;
		cnt++;
		cv[cnt]=a[i];
		if(cnt==n-1)  break;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

