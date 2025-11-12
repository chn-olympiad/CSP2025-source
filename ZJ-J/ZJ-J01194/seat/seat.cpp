#include<bits/stdc++.h>
using namespace std;
int m, n, f = 1, a, in, ans[2] = {0};

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 0; i < n * m - 1; i++){
		cin >> in;
		if (in > a) f++;
	}
	
	ans[0] = (f - 1) / n + 1;
	if(ans[0] % 2 == 0) ans[1] = n * ans[0] - f + 1;
	else ans[1] = f - n * (ans[0] - 1);
	
	cout << ans[0] << ' ' << ans[1] << endl;
	
	return 0;
}