#include <bits/stdc++.h>
using namespace std;
long long int inf=998244353;
int n;
long long int ans=0,sum=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for(int l=0;l<n-1;l++) {
		for(int r=l+1;r<n;r++) {
			sum=0;
			int nmax=0;
			for(int i=l;i<=r;i++) {
				sum+=a[i];
				if(a[i]>nmax) {
					nmax=a[i];
				}
			}
			if(sum>nmax*2&&l-r+1>=3) {
				ans++;
			}
		}
	}
	cout<<ans%inf;
	return 0;
}
