#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[5005], b[5005];
int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n - i; j++){
			int ma = -1;
			for(int k = i - 1; k <= i + j - 1; k++){
				if(a[k] > ma){
					ma = a[k];
				}
			}
			int sum = 0;
			for(int k = i - 1; k <= i + j - 1; k++){
				sum += a[i];
			}	
			if(sum > ma){
				ans++;
			}
		}
	}
	cout << ans - 1;
	
	return 0;
}
