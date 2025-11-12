#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a[100010][11],b[100010];
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int c1=0,c2=0,c3=0;
		ll ans=0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][1]>=max(a[i][2],a[i][3])) c1++;
			else if (a[i][2]>=max(a[i][1],a[i][3])) c2++;
			else c3++;
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if (max(c1,max(c2,c3))<=n/2) printf("%lld\n",ans);
		else {
			if (c1>n/2) {
				for (int i=1;i<=n;i++) {
					if (a[i][1]>=max(a[i][2],a[i][3])) 
						b[i]=a[i][1]-max(a[i][2],a[i][3]);
					else b[i]=1e9;
				}
			}
			else if (c2>n/2) {
				for (int i=1;i<=n;i++) {
					if (a[i][2]>=max(a[i][1],a[i][3])) 
						b[i]=a[i][2]-max(a[i][1],a[i][3]);
					else b[i]=1e9;
				}
			}
			else {
				for (int i=1;i<=n;i++) {
					if (a[i][3]>=max(a[i][2],a[i][1])) 
						b[i]=a[i][3]-max(a[i][2],a[i][1]);
					else b[i]=1e9;
				}
			}
			sort(b+1,b+n+1);
			for (int i=1;i<=max(c1,max(c2,c3))-n/2;i++) ans-=b[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
