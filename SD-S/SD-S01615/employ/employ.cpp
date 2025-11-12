#include<bits/stdc++.h>
using namespace std;
const long long N = 505;
long long n,m,ans;
string s;
long long c[N],a[N];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ1.in","r",stdin);
//	freopen("employ2.in","r",stdin);
//	freopen("employ3.in","r",stdin);
//	freopen("employ4.in","r",stdin);
//	freopen("employ5.in","r",stdin);
	cin>>n>>m>>s;
	s = " " + s;
	for(long long i = 1;i <= n;i ++) {
		cin>>c[i];
		a[i] = i;
	}
	do {
		long long t = 0,p = 0;
		for(long long i = 1;i <= n;i ++) {
			long long r = a[i];
			if(t >= c[r]) {
				t ++;
			}
			else if(s[i] == '1') {
				p ++; 
			}
			else {
				t ++;
			}
		}
		if(p >= m) {
			ans ++;
//			for(long long i = 1;i <= n;i ++) cout<<a[i]<<" ";cout<<"\n";
		}
	}while(next_permutation(a + 1,a + n + 1));
	cout<<ans<<"\n";
	return 0;
}


