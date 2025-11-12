#include <bits/stdc++.h>
using namespace std;
int n,m,a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	int R = a[1];
	sort(a+1,a+n*m+1);
	for (int i = 1;i <= n*m;i++){
		if (a[i] == R){
			R = i;
			break;
		}
	}
	int c,r;
	if (R % n == 0){
		c = R/n;
	}
	else{
		c = R/n+1;
	}
	if (c % 2 == 0){
		if (R % n == 0){
			r = 1;
		}
		else{
			r = 5 - R%n;
		}
	}
	else{
		if (R % n == 0){
			r = 4;
		}
		else{
			r = R%n;
		}
	}
	cout << c << " " << r;
	return 0;
}
