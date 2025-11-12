#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 5e6 + 10;
int n, q, idx, d, ans;
string s[N][2], t1, t2;
int zheng[M], fu[M];
int main(){
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i ++){
		cin >> t1 >> t2;
		s[i][0] = t1;
		s[i][1] = t2; 
		d = t1.find('b') - t2.find('b');
		if(d < 0) fu[abs(d)] ++;
		else zheng[d] ++;
	}
	for(int i = 1; i <= q; i ++){
		cin >> t1 >> t2;
		d = t1.find('d') - t2.find('d');
		if(d < 0) ans += fu[abs(d)];
		else ans += zheng[d];
		printf("%d\n", ans);
	}
	return 0;
}
