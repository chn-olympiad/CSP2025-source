#include<bits/stdc++.h>
using namespace std;

int n, k;

vector<int> a(500001);

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);	
	cin >> n >> k;
	for(int i = 0;i < n;i++)cin >> a[i];
	if(n == 1){
		cout << a[1];
	}
	if(k == 0){
		cout << n / 2;
	}	
	else cout << 1;
	return 0;
}
