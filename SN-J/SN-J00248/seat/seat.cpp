#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		if(a[0] < a[i]){
			cout << n << " " << m;
			return 0;
		}
	}
	return 0;
}
