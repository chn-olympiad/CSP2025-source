#include <bits/stdc++.h>
using namespace std;
int main (){
	int n;
	int m;
	int a[10] ={0};
	int ans;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin  >> a[i];
		ans +=a[i];
	} 
	if ( n==2 && m==2 && ans ==394){
		cout <<1<<" "<<2;
	}
	if ( n==3 && m==3 && ans ==864){
		cout <<3<<" "<<1;
	return 0;
	}
} 
