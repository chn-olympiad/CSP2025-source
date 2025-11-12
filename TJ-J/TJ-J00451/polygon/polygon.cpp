#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int max;
	max = b;
	if(c > max)max = c;
	if(d > max)max = d;
	if((b + c + d - max) > 2 * max){
		cout << 1;
	}else cout << 0;
}
