#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	int a[m * n + 10];
	int num, num2 = 0;
	int h = 0;
	for(int i = 0; i < m * n; i++){
		cin >> a[i];
		num = a[0];
	}
	for(int i = 0; i < m * n; i++){
		if(a[0] < a[i]){
			for(int i = 0; i < m * n; i++){
		if(num >= a[i]){
			num2++;
		} 
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			while(num2 >= 0){
				num2 -= n;
				h++;
			}
			if(m % 2 == 0){
					cout << h << " " << n + num2;
					break;
				}else{
					cout << h << " " << -num2;
					break;
			}
		}
	}
		}else{
			cout << 1 << " " << 1;
		}
	}
	
	return 0;
}
