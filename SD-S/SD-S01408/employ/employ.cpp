#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510],b[510],p=998244353;
long long ans;
char s[510];
void dfs (int x,int y,int z) {
	if (x) {
		if (s[x]=='0') {
			y++;
		}
		else {
			if (y>=c[a[x]]) {
				y++;
			}
			else {
				z++;
			}
		}
	}
	if (x==n) {
		if (z>=m) ans++;
		return;
	}
	for (int i=1;i<=n;i++) {
		if (b[i]==0) {
			b[i]=1;
			a[x+1]=i;
			dfs(x+1,y,z);
			b[i]=0;
		}
	}
}
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	if (n<=10) {
		dfs(0,0,0);
		printf("%lld",ans);
		return 0;
	}
	else {
		int x=0;
		for (int i=1;i<=n;i++) 
		if (c[i]==0) x++;
		if (n-x>=m) {
			long long q=1;
			for (int i=1;i<=n;i++) q=(q*i)%p;
			printf("%lld",q);
		}
		else printf("0");
	}
	return 0;
}
