#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("xor.in","r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >>k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	cout << n;
	return 0;
}
