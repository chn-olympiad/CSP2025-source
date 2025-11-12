#include<bits/stdc++.h>
using namespace std;

int n, a[5005], c, maxn = 0; 

int main() {	

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
		
	}
	for(int i = 1; i <= n; i++){
		cin >>  a[i];
		c += a[i];
		maxn = max(maxn, a[i]);
	}
	if(c - maxn > maxn){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
} 
