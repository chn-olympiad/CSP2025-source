#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,mod_1=998,mod_2=244,mod_3=353;
ll n,a[N],b[N],ans=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=3) {
		if(n<3) {
			cout<<0;
			return 0;
		}
		if(a[0]+a[1]>a[2]) {
			cout<<1;
			return 0;
		} else {
			cout<<0;
			return 0;
		}
	} else {
		b[0]=a[0];
		for(int i=1; i<n; i++) {
			b[i]=a[i]+b[i-1];
		}
		for(int i=0; i<n; i++) {
			for(int j=i+3; j<=n; j++) {
				if(b[j]-b[i]+a[i]>2*a[j]) {
					ans++;
					ans%=mod_1;
					ans%=mod_2;
					ans%=mod_3;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
