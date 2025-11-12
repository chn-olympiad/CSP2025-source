#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int main(){
	freopen("seat.in","r", stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int r = a[1];
	for(int i = 1; i <= n * m; i++){
		for(int j = 1; j <= n * m; j++){
			if(a[j] < a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				
			}
		}
	} 
	int x;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == r){
			x = i;
		}
	}
	if(x % n == 0){
		cout << x / n << " ";
		if(x / n % 2 == 1){
			cout << n;
		}else{
			cout << 1;
		}
		return 0;
	}else{
		cout << x / n + 1 << " ";
		if((x / n + 1) % 2 == 1){
			cout << x % n;
		}else{
			cout << n - x % n + 1;
		}
	}
	//如果X可以被n整除，先输出x/n, 且在奇数列，则直接输出n
	//                             若是在偶数列，则输出1 
	//若x不能被n整除，输出x/n+1, 如果在奇数列，输出x%n 
	//                             若是在偶数列，n - x % n + 1 
	return 0;
}
