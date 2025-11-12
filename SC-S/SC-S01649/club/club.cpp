#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		int n,a[maxn],a1,b[maxn],b1,c[maxn],c1,ans;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
			if((a[i]>b[i]) || (b[i]<c[i])) {
				if(a[i]>c[i]) {
					ans+=a[i];
					a1++;
				} else {
					ans+=c[i];
					c1++;
				}
			}
			if(a[i]<b[i] || a[i]<c[i]) {
				if(b[i]>c[i]) {
					ans+=b[i];
					b1++;
				} else {
					ans+=c[i];
					c1++;
				}
			}
			if(b[i]>c[i] || a[i]>c[i]) {
				if(a[i]>b[i]) {
					ans+=a[i];
					a1++;
				} else {
					ans+=b[i];
					b1++;
				}
			}
		}
		cout<<ans/2;
		for(int i=1;i<=n;i++) {
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
	}
	return 0;
} 