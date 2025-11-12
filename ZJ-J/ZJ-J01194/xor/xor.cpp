#include<bits/stdc++.h>
using namespace std;
#define L 500002
int n, k, a[L], b[L] = {0};

bool ad(int s, int e, int ads){
	bool fs = true;
	for (int i = s; i <= e; i++){
		b[i] ^= ads;
		if (b[i] == k) fs = false;
	}
	return fs;
}

int f(int s, int as){
	if (s >= n) return as;
	int f1 = s;
	while (ad(s, f1, a[f1]) and f1 < n - 1) f1++;
	if (f1 >= n - 1) as--;
	return f(f1 + 1, as + 1);
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << f(0, 0) << endl;
	
	return 0;
}