#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[500005];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i != 1){
			a[i] ^= a[i-1];
		}
	}
	int last = 0, times = 0;
	for(int j = 1;j <= n;j++){
		for(int i = last+1;i <= j;i++){
			if((int)(a[j]^a[i-1]) == k){
				times++;
				//cout << "[" << i << "," << j << "] picked" << endl;
				last = j;
				break;
			}
		}
	}
	cout << times << endl;
	return 0;
}
