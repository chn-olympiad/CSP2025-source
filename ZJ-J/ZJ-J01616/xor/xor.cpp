#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],f[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	map<long long,long long> m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=0; i<=n; i++) {
		if(i>=1) {
			f[i]=max(f[i],f[i-1]);
		}
		f[i]=max(f[i],m[a[i]]);
		int num=(a[i]^k);
		m[num]=max(m[num],f[i]+1);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
