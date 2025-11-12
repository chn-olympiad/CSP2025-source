#include <bits/stdc++.h>
using namespace std;
long long t, n, sum;
struct node{
	long long ai1, ai2, ai3;
 } a[100005]; 
bool cmp(node x, node y){
	return x.ai1 > y.ai1;
}
bool f = 1;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		f = 1;
		sum = 0;
		for (int i = 1; i <= n; i++){
			a[i].ai1 = a[i].ai2 = a[i].ai3 = 0;
		}
		for (int i = 1; i <= n; i++){
			cin >> a[i].ai1 >> a[i].ai2 >> a[i].ai3;
			f = (a[i].ai2 == 0ll && a[i].ai3 == 0ll);
		}
		if (n == 2){
			int x = a[1].ai1 + a[2].ai2;
			int b = a[1].ai1 + a[2].ai3;
			int c = a[1].ai2 + a[2].ai1;
			int d = a[1].ai2 + a[2].ai3;
			int e = a[1].ai3 + a[2].ai1;
			int f = a[1].ai3 + a[2].ai2;
			cout << max({x, b, c, d, e, f}) << '\n';
		}
		else if (f){
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++){
				sum += a[i].ai1;
			}
			cout << sum << '\n';
		}
		
	}
	return 0;
}
