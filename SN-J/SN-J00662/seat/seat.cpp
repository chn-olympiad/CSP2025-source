#include <bits/stdc++.h>
using namespace std;

int num[105], list[15][15], v, u;
int n, m;
int k, a, b;
int p;
int t[105] = {0};

int grade, score;

int main() {

freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

	cin >> n >> m;
	u = n * m;
	for(int i = 1;i <= u ;i++) {
		cin >> v;
		if(i == 1) score = v;
		t[v] = 1;
	}
	for(int i = 100;i >= 1;i--) {
		if(t[i] == 1) grade++;
		if(i == score) break;
	}
	
	k = grade;
	a = k / n;
	b = k % n;
	
	//cout << k << endl << a << endl << b << endl;
	
	if(b != 0) {
		p = a + 1;
		if(p % 2 != 0) {
			cout << p << " " << b;
		}
		if(p % 2 == 0) {
			cout << p << " " << (n - b + 1);
		}
		return 0;
	}
	if(b == 0) {
		if(a % 2 != 0) {
			cout << a << " " << n;
		}
		if(a % 2 == 0) {
			cout << a << " " << 1;
		}
		return 0;
	}
}

