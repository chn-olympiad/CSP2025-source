#include <bits/stdc++.h>
using namespace std;

int n, m;
string a;
int num[510];
int nm[510][2], l2;
int q[510] = {0};
int s = 0, k, l, r = 0;
int cnt = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 0; i < n; i++){
		cin >> num[i]; 
	}
	sort(num, num + n);
	for(int i = 0; i < n; i++){
		if(num[i] == nm[l2][0]) nm[l2][1]++;
		else nm[l2 + 1][0] = num[i]; nm[l2+1][1] = 1; l2++;
	}
	l = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == '0'){
			s++;
			q[r] = l;
			l = 0;
			r++;
		}
		else l++;
	}
	k = n - s - m;
	for(int i = 0; i < l2; i++){
		if(q[num[i]] + k > 0) cnt *= nm[i][1] * (q[nm[i][0]] + k); cnt %= 998244353;
	}
	cout << cnt+1;
	return 0;
}
