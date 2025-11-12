#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, k, sum = 0, cnt = 0;
int max_cnt = -1;
int a[N] = {};

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0;i < n;++i){
		cin >> a[i];
	}
	for(int j = 0;j < n;++j){
		cnt = 0;
		for(int i = j;i < n;++i){
			sum ^= a[i];
			if (sum == k) {
				cnt++;
				sum = 0;
			}
		}
		if (cnt > max_cnt) max_cnt = cnt;
	}
	cout << max_cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
