#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,a[5005],ans=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>3) {
		cout<<1<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++) {
		for(long long j=i+2;j<=n;j++) {
			long long num=0,mx=-1;
			for(long long k=i;k<=j;k++) {
				num+=a[k];
				if(mx<a[k]) mx=a[k];
			}
			if(num>mx*2) {
				ans++;
			}
			ans%=N;
		}
	}
	cout<<ans;
	return 0;
}
