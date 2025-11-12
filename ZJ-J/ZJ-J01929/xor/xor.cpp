#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
long long n,k,a[N],ans=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++) {
		for(long long j=i+1;j<=n;j++) {
			long long num=a[i];
			for(long long k=i+1;k<=j;k++) {
				num=!num|a[k];
			}
			if(num==k) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
