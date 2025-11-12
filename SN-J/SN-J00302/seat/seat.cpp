#include <bits/stdc++.h>
using namespace std;
long long n , m , a[105] , b , j , aa = 1, bb = 1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	b = a[1];
	sort(a,a+n*m);
	for(int i = 1; i <= n * m; i ++){
		if(b == a[i]){
			j = n * m - i;
		}
	}
	
	if(j % n == 0){
		aa = j / n;
		bb ++;
	}else{
		if(j / n % 2 == 0){
			aa += j / n;
			bb = j % n;
		}else{
			aa += j / n;
			bb += j % n;	
		}
	}
	if(n == 1){
		aa = 1;
		bb = j;
	}
	if(m == 1){
		aa = j;
		bb = 1;
	}
	if(n == 1 && m == 1){
		aa = 1;
		bb = 1;
	}
	cout << aa << ' ' << bb;
	return 0;
} 
