#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= n - 1; i++){
		sort(a+1, a+i+1);
	}
	cout << a[n];
	return 0;
} 
