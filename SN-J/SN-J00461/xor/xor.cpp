#include <bits/stdc++.h>
using namespace std;

long long a[10000000];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n, k;
	cin >> n >> k;
	for(long long i = 1; i <= n; i ++){
		cin >> a[i];
	}
	long long ans = 0;
	for(long long i = 1; i <= n; i ++){
		for(long long j = i; j <= n; j ++){
			long long tmp,ed;
			if(a[j] == 0){
				continue;
			}else{
				ed = j;
			}
			for(long long x = i; x <= ed; x ++){
				if(a[x] == 0){
					continue;
				}
				if(x == i){
					tmp = a[i];
					continue;
				}
				tmp = tmp ^ a[x];
			}
			if(tmp == k){
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}
