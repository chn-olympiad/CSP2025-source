#include <iostream>
#include <vector>
using namespace std;
long long n, arr[100010][3];

long long out1() {
	long long rst = 0, brr[3] = {}, sum = 0, v[100010];

	while(1) {
		bool flag = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(v[i] > 2) {
				if(i > 0) {
					v[i] = 0;
					v[i - 1]++;
				} else {
					flag = 1;
					break;
				}
			} else {
				break;
			}
		}
		if(flag) break;
		brr[0] = 0, brr[1] = 0, brr[2] = 0;
		for(int i = 0; i < n; i++) {
			sum += arr[i][v[i]];
			brr[v[i]]++;
			//printf("%d ", v[i]);
		}
		//printf("\n");
		if(brr[0] <= n / 2 && brr[1] <= n / 2 && brr[2] <= n / 2) {
			rst = max(sum, rst);
			//cout << rst;
		}
		sum = 0;
		v[n - 1]++;
	}
	return rst;
}
long long out2() {
	long long rst = 0, brr[2] = {}, sum = 0, v[100010];

	while(1) {
		bool flag = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(v[i] > 1) {
				if(i > 0) {
					v[i] = 0;
					v[i - 1]++;
				} else {
					flag = 1;
					break;
				}
			} else {
				break;
			}
		}
		if(flag) break;
		brr[0] = 0, brr[1] = 0;
		for(int i = 0; i < n; i++) {
			sum += arr[i][v[i]];
			brr[v[i]]++;
			//printf("%d ", v[i]);
		}
		//printf("\n");
		if(brr[0] <= n / 2 && brr[1] <= n / 2) {
			rst = max(sum, rst);
			//cout << rst;
		}
		sum = 0;
		v[n - 1]++;
	}
	return rst;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		n = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}
//		for(int i = 0; i < n; i++) {
//			cout << arr[i][0] << ' ' << arr[i][1] << ' ' << arr[i][2] << endl;
//		}
		if(n < 30)
			cout << out1() << endl;
		else {
			cout << out2() << endl;
		}
	}
}