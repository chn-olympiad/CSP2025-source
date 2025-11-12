#include <bits/stdc++.h>
using namespace std;

map<long long,long long> m;

// cannot prove and connot gen wrong samples.
// STO OTZ //freopen while(1) kkksc03 \o/\o/\o/ OVOVOVO

int main(){
	//#ifndef MDEBUG
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//#endif
	long long n,k;
	cin >> n >> k;
	long long sum = 0,lst =-1,ans=0;
	m[0]=0;
	for(long long i = 1;i <= n;++i){
		long long x;
		cin >> x;
		sum ^= x;
		if(m.count(sum^k) != 0){
			//cout << m[sum^k] << '-' << i;

			if(m[sum^k]>=lst){
				++ans;
				lst=i;
			}
		}
		m[sum]=i;

	}
	cout << ans;
	//while(1);
}
