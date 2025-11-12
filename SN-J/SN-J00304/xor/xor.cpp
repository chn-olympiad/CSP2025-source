#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int a[MAXN], arr[MAXN], n, k, ans, s;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		arr[i] = arr[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i ++){
		for (int j = s; j < i; j ++){
			if ((arr[i] ^ arr[j]) == k){
				s = i;
				ans ++;
				break;
			}
			
		}
	}
	cout << ans;
	return 0;
}
