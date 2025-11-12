#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if(a+b > c){
		if(b+c > a){
			if(a+c > b){
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
