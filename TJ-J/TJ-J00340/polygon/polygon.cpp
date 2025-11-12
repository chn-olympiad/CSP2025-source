#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c){
	int maxa = max(a, b);
	maxa = max(maxa, c);
	int sum = a + b + c;
	if (sum > 2 * maxa)
		return true;
	else 
		return false;
}

bool check4(int a, int b, int c, int d){
	int maxa = max(a, b);
	maxa = max(maxa, c);
	maxa = max(maxa, d);
	int sum = a + b + c + d;
	if (sum > 2 * maxa)
		return true;
	else 
		return false;
}

bool check5(int a, int b, int c, int d, int e){
	int maxa = max(a, b);
	maxa = max(maxa, c);
	maxa = max(maxa, d);
	maxa = max(maxa, e);
	int sum = a + b + c + d + e;
	if (sum > 2 * maxa)
		return true;
	else 
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int sum = 0;
	if(n < 3) {
		sum = 0;
	}
	if(n = 3) {
		if (check(a[0], a[1], a[2])) sum = 1;
		else sum = 0;
	}
	if(n = 4) {
		if (check(a[0], a[1], a[2])) sum++;
		if (check(a[0], a[1], a[3])) sum++;
		if (check(a[0], a[2], a[3])) sum++;
		if (check(a[1], a[2], a[3])) sum++;
		if (check4(a[0], a[1], a[2], a[3])) sum++;
	}
	if(n = 5) {
		if (check(a[0], a[1], a[2])) sum++;
		if (check(a[0], a[1], a[3])) sum++;
		if (check(a[0], a[1], a[4])) sum++;
		if (check(a[0], a[2], a[3])) sum++;
		if (check(a[0], a[2], a[4])) sum++;
		if (check(a[0], a[3], a[4])) sum++;
		if (check(a[1], a[2], a[3])) sum++;
		if (check(a[1], a[2], a[4])) sum++;
		if (check(a[1], a[3], a[4])) sum++;
		if (check(a[2], a[3], a[4])) sum++;
		if (check4(a[0], a[1], a[2], a[3])) sum++;
		if (check4(a[0], a[1], a[2], a[4])) sum++;
		if (check4(a[4], a[1], a[2], a[3])) sum++;
		if (check4(a[0], a[4], a[2], a[3])) sum++;
		if (check4(a[0], a[4], a[1], a[3])) sum++;
		if (check5(a[0], a[1], a[2], a[3], a[4])) sum++;
	}
	cout << sum;
	
	return 0;
}
