#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	srand(time(0));
	ll n, m;
	cin >> n >> m;
	cout << rand()*rand()*rand() / m % n *rand() % n *n % 998244353;
}