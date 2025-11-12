#include<iostream>
#include<fstream>
using namespace std;
//列数：x/n
//行数: 列数奇数： x % n
//偶数： n - x%n - 1
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long m, n;
	cin >> n >> m;
	long long h, a;
	cin >> h;
	long long sumb, sums;
	sumb = 0;
	sums = 0;
	for(long long i = 0;i < n * m - 1;i++){
		cin >> a;
		if(a > h){
			sumb++;
		}else sums++;
	}
	long long x;
	x = sumb;
	cout << x / n + 1<< ' ';
	if(((x / n) + 1)% 2== 1){
		cout << x%n + 1;
	}else cout << n - x%n;
	return 0;
}
