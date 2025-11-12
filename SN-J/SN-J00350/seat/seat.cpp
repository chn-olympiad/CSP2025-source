#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m , x , y , s , p;
	cin >> n >> m;
	int a[101] = {};
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == s){
			p = n * m - i + 1;
			break;
		}
	}
	if(p % n != 0){
		y = p / n + 1;
	}
	else{
		y = p / n;
	}
	if(y % 2 == 1){
		if(p % n == 0){
			x = n;
		}
		else{
			x = p % n;
		}
	}
	else if(y % 2 == 0){
		if(p % n == 0){
			x = 1;
		}
		else{
			x = n - (p % n) + 1;
		}
	}
	cout << y << " " << x;
	return 0;
}
