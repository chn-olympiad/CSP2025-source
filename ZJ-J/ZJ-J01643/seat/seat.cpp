#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int t = a[1];
	sort(a+1, a+n*m+1);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == t){
			t = n*m-i+1;
			break;
		}
	}
	int x = 1, y = 1;
	for(int i = 2; i <= t; i++){
		if(x%2 == 1){
			if(y != n){
				y++;
			}else{
				x++;
			}
		}else{
			if(y != 1){
				y--;
			}else{
				x++;
				y = 1;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}