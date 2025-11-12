#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5e5 + 100;
int n, k, ans[N] = {}, a[N] = {}, s[N] = {};

int main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];

	if(n >= 2e5){
		int c = 0;
		if(k == 1) for(int i = 1; i <= n; i++) c += a[i];
		else{
			for(int i = 1; i <= n; i++){
				if(a[i] == 0) c++;
				else if((a[i] ^ a[i - 1]) == 0) c++, a[i] = 0, a[i - 1] = 0;
			}
		}
		cout << c << "\n";
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] == k){
			ans[i] = max(ans[i - 1] + 1, ans[i]);
			continue;
		}
		int cnt = 0;
		ans[i] = max(ans[i - 1], ans[i]);
		for(int j = i + 1; j <= n; j++){
			if((s[j] ^ s[i - 1]) == k){
				cnt++;
				ans[j] = max(ans[i - 1] + cnt, ans[j]);
				break;
			}
			ans[j] = max(ans[i - 1] + cnt, ans[j]);
		}
	}
	
	cout << ans[n] << "\n";

	return 0;
}


