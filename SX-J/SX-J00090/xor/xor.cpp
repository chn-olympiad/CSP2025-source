#include <iostream>
using namespace std;
unsigned long long n, k, arr[500010] = {}, brr[500010] = {}, rst = 0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		brr[i] = arr[i] ^ brr[i - 1];
		//cout << brr[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if((brr[i - 1] ^ brr[j]) == k) {
				//cout << i << j << endl;
				rst++;
			}
		}
	}
	cout << rst;
	return 0;
}