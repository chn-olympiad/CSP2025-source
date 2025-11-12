#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[100010];
	int x = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n-1; i++){
		x+=i;
	}
	cout << x;
	
	
	return 0;
}
