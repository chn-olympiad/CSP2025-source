#include <bits/stdc++.h>
using namespace std;

const int N=5005,mod=998244353;
int n,m,a[N],d[N],ans;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n),d[0]=1;
	for(int i=1;i<=n;i++) {
		if(i>2) for(int j=a[i]+1;j<=m;j++) (ans+=d[j])%=mod;
		m=min(m+a[i],5001);
		for(int j=m;~j;j--) (d[min(j+a[i],m)]+=d[j])%=mod;
	}
	printf("%d\n",ans);
	return 0;
}

// AK at 9:10
// luogu uid806330
