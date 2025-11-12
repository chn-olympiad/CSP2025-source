#include <bits/stdc++.h>
using namespace std;
long long l[100860];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> l[i];
	int ans = 0;
	if(n == 1){
		cout << 0;
	}else if(n == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int zhi = max(l[i], l[j])*2;
				if(l[i] +l[j] > zhi) ans++;
			}
		}
		cout << ans;
	}else if(n == 3){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int zhi = max(l[i], l[j])*2;
				if(l[i] +l[j] > zhi) ans++;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					int zhi = max(max(l[i], l[j]), l[k])*2;
					if(l[i] + l[j] + l[k] > zhi) ans++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
