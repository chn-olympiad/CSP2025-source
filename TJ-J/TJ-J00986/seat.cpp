#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m,c,r;
	cin >> n >>m;
	for (int i = 0;i < n * m;i ++){
		cin >> a[i];
	}
	int s = a[0],d;
	sort(a,a + n * m);
	for (int i = n * m - 1;i >= 0;i --){
		if (a[i] == s){
			d = n * m - i;
			break;
		}
	}
	if (d % m == 0) r = d / m;
	else r = d / m + 1;
	if (r % 2== 1){
		c = d % m;
	}
	else{
		c = n - d % n + 1;
	}
	cout << r << " "  << c;
	return 0;
}
