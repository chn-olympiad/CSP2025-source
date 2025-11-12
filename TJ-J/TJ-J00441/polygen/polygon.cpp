#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	cin >> a >> b >> c;
	if(n < 3) cout << 0;
	if(n == 3){
		if(a > b && a > c){
			if(b+c > a) cout << 1;
		}
		
		if(b > a && b > c){
			if(a+c > b) cout << 1;
		}
		if(c > a && c > b){
			if(a+b > c) cout << 1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
