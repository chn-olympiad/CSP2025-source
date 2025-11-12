#include <bits/stdc++.h>

using namespace std;

const int N = 520;

int n, m, ans;
string s;
int c[N], a[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i ++ ){
		scanf("%d", &c[i]);
		a[i] = i;
	}
//	for (int i = 0; i < s.size(); i ++ ){
//		a[i] = a[i - 1] + int(s[i]) - 48;
//	}
	int ss = 0;
	do{
		ss ++ ;
	}while(next_permutation(a + 1, a + n + 1));
	cout << ss;
	return 0;
}
