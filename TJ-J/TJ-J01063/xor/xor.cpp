#include<bits/stdc++.h>
using namespace std;
int r[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, sum, l = 0;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> r[i];
	}
	for (int i = 0;i < n;i++) {
		int temp = r[i];
		for (int j = 0;j < n;j++) {
			if (temp == k and j > l) {
				sum++;
				i++;
				j++;
				l = max(l, j - 1);
				continue;
			}
			temp = temp ^ r[j];
		}
	}
	cout << sum;
	return 0;
}
