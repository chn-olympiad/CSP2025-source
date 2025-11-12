#include<bits/stdc++.h>
using namespace std;
const int mn = 1000001;
int a[mn];
int h[mn] = {};
int main() {
    freopen("seat.in", "r", "stdin");
    freopen("seat.out", "w", "stdout");
	int n, m;
	cin >> n >> m;
	int g = n * m;
	for(int i = 1; i <= g; i++) {
		cin >> a[i];
		h[i] = a[i];
	}
	cout << n <<" "<< m;
}
