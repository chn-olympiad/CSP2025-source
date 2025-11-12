#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,x,f[500005],cnt,ans,now;
struct sjx {
	int l,r;
} a[20000005];
int cmp(sjx x,sjx y) {
	return x.r<y.r;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>x,f[i]=f[i-1]^x;
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			if((f[j]^f[i-1])==k)
				cnt++,a[cnt].l=i,a[cnt].r=j;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1; i<=cnt; i++)
		if(a[i].l>a[now].r)
			ans++,now=i;
	cout<<ans<<"\n";
	return 0;
}
//csprp++;
//60 pts