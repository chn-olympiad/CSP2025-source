#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, an, cnt = 0;
int b[105];
int cmp(int x, int y){
	return x > y;
}
signed main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> b[i];	
	}
	an = b[1];
	int num = 0, x = 0, y = 1, f = 0;
	sort(b + 1, b + (n * m) + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(b[i] == an){
			num = i;
		}
	}
//	cout << num << endl;
	while(num--){
		if(f == 0){
			x++;
			if(x > n){
				f = 1;
				x -= 1;
				y++;
			}
//			cout << y << ' ' << x << endl;
		}
		else{
			x--;
			if(x < 1){
				f = 0;
				x += 1;
				y++;
			}
//			cout << y << ' ' << x << endl;
		}
	}
	cout << y <<' ' << x;
	
	return 0;
}
