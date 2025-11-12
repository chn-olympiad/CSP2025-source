#include<bits/stdc++.h>
using namespace std;
#define L 5003
int n, ys[L][2], ml, f2 = 0, ans = 0;

int f(int s, int sums, int max1, int ns){
	if (s < 0) return 0;
	if (sums > max1) {
		int as = 1;
		for (int i = 0; i <= s; i++) as *= ys[i][1] + 1;
		return as;
	}
	int f1 = 0, su = 0;
	while (f1 <= ys[s][1] and (sums + f1 * ys[s][0] <= max1 or ns + f1 < 3)){
		su += f(s - 1, sums + f1 * ys[s][0], max1, ns + f1);
		max1 = max(max1, ys[s][0] * 2);
		f1++;
	}
	if (f1 > ys[s][1]) f1--;
	if (s != 0 and sums + f1 * ys[s][0] > max1 and ns + f1 > 2){
		int s1 = 1;
		for (int i = 0; i <= s - 1; i++) s1 *= ys[i][1] + 1;
		su += s1 * (ys[s][1] - f1 + 1);
	}
	return su;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ml;
		ys[ml][0]++;
	}
	for (int i = 1; i < L; i++){
		if (ys[i][0] != 0){
			ys[f2][1] = ys[i][0];
			ys[f2][0] = i;
			f2++;
		}
	}
	cout << f(f2 - 1, 0, 0, 0) + 1 << endl;
	
	return 0;
}