#include <iostream>
using namespace std;
int main(){
	int n,m,sum;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << 1 << " " << 1;
		return 0; 
	}
	int a[m*n+1];
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
		sum = a[1];
	}
	int w = 1;
	for(int i = 1; i <= n * m; i++){
		if(a[i] > sum){
			w++;
		}
	}

	int x,y;
	if(w % n != 0){
		x = w / n + 1;
	}else{
		x = w / n;
	}
	cout << x << " ";
	if(w % n != 0){
		cout << w - n * (x - 1);
	}else if(w % n == 0){
		cout << n;
	} 
	
	
	return 0;
} 
