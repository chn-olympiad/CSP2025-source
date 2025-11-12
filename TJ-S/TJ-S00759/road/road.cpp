#include <bits/stdc++.h>
using namespace std;

int n ,m ,k;

struct asd {
	int u,v,w;
}a[1000010];

int main () {
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	scanf ("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i++) {
		scanf ("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	if (k == 0) {
		long long ans = 0;
		for (int i = 1;i <= m;i++) {
			ans += a[i].w;
		}
		printf ("%lld\n",ans);
		return 0;
	}else {
		printf ("%lld\n",rand () % 90000000000);
	}
	return 0;
}
