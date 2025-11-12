#include <bits/stdc++.h>
using namespace std;
int n, k, sum = 0;
bool ifxor(int x, int y, int a[]){
	int ans = 0;
	for(int i = x;i <= y;i++)
		ans = ans ^ a[i];
	if(ans == k){
		sum++;
		return true;
	}
	return false;
}
int main(){
	cin.tie();cout.tie();
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int a[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			if(ifxor(i, j, a))
				i = j + 1;
		}
	}
	cout << sum;
	return 0;
}
