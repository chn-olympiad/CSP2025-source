#include <bits/stdc++.h>
using namespace std;
int n,m,b[102],x,y,z,j = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> b[i];
	}
	x = b[1];
	sort(b + 1,b + 1 + n + m);
	for(int i = n * m;i >= 1;i--){
		if(b[i] == x) y = j;
		j++;
	}
	//cout << y;
	if(y <= n){
		cout << 1 << " " << y << "\n";
	}else if(y > n and y <= 2 * n){
		cout << 2 << " " << y - y % n << "\n";
	}else if(y > n * 2 and y <= 3 * n){
		cout << 3 << " " << y - 2 * n << "\n";
	}else if(y > n * 3 and y <= 4 * n){
		cout << 4 << " " << y - 2 * n - y % n << "\n";
	}else if(y > n * 4 and y <= 5 * n){
		cout << 5 << " " << y - 4 * n << "\n";
	}else if(y > n * 5 and y <= 6 * n){
		cout << 5 << " " << y - 4 * n - y % n << "\n";
	}else if(y > n * 6 and y <= 7 * n){
		cout << 6 << " " << y - 6 * n << "\n";
	}else if(y > n * 7 and y <= 8 * n){
		cout << 7 << " " << y - 6 * n - y % n << "\n";
	}else if(y > n * 8 and y <= 9 * n){
		cout << 8 << " " << y - 8 * n << "\n";
	}else if(y > n * 9 and y <= 10 * n){
		cout << 9 << " " << y - 8 * n - y % n << "\n";
	}
	return 0;
}
