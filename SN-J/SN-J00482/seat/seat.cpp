#include<bits/stdc++.h>
using namespace std;

int n, m, t, A, B;

struct Info{
	int a, b;
	bool operator< (const Info &A) const {
		return a > A.a;
	}
} a[110];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].a;
		a[i].b = i;
	}
	sort(a + 1, a + (n * m) + 1);
	for(int i = 1; i <= (n * m); i++){
		if(a[i].b == 1){
			t = i;
		}
	}
	A = t / n + ((t % n) != 0);
	B = t % n;
	if(B == 0){
		B = n;
	}
	if(A % 2 == 0){
		B = n - B + 1;
	}
	cout << A << " " << B << "\n";
	return 0;
}
