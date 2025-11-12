#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll n, k, a[N],sum1,sum0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i]==1){
			sum1++;
		}else if(a[i]==0){
			sum0++;
		}
	}
	if(k==0){
		ll cnt=0;
		for(int i=1;i<n;i+=2){
			if(a[i]==1 && a[i+1]==1){
				cnt++;
			}
		}
		cout<<cnt+sum0;
	}else if(k==1){
		cout<<sum1;
	}
	return 0;
}
