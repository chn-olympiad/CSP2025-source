#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,K=1<<20|5;
int n,k,a[N],d[K],f[N],ans;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	memset(d,0xbf,sizeof(d)),d[0]=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans,f[i]=max(f[i-1],d[a[i]^k]+1));
		d[a[i]]=max(f[i],d[a[i]]);
	}
	return printf("%d\n",ans),0;
}
