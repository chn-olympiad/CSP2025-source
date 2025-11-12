#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int t = 0;
	for (int i = 0; i < n; ++i){
		char a;
		cin >> a;
		if (a == '1') ++t;
	}
	for (int i = 0; i < n; ++i){
		int a;
		cin >> a;
	}
	long long res = 1;
	for (long long i = 2; i <= t; ++i){
		res *= i;
		res %= 998244353;
	}
	cout << res;
	return 0;
}


