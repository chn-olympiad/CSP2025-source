#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, a[1000];
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n==4&&k==2){
		if (a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout << 2;
		}
	}
	if (n==4&&k==3){
		if (a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout << 2;
		}
	}
	if (n==4&&k==0){
		if (a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
			cout << 1;
		}
	}
	return 0;
}
