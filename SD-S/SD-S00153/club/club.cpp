#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,maxn=0,ans=0;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(n==2) {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
				ans=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))));
			}
		} else {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
				maxn=max(a[i],max(b[i],c[i]));
				ans+=maxn;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
