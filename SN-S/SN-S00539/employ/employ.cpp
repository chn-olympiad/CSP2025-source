#include <bits/stdc++.h>
using namespace std;

long long f(long long x){
	long long ans = 1;
	for (long long i = 1; i <= x; i++){
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	int num[n]
	for (int i = 0; i < n; i++){
		cin >> num[i]
	}
	cout << f(n) << "\n"
	fclose(stdin);
	fclose(stdout);
	return 0;
}
