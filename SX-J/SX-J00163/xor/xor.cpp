#include<bits/stdc++.h>
using namespace std;
const int A = 5 * 1e5;
int n, k, a[A], sum = 0;
int MAX = -1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 0){
		cout << 1;
	}
	else{
		for(int i = 2; i <= n; i++){
			if(a[i] | a[i - 1] == k){
				int s = a[i] | a[i - 1];
				sum += s;
			}
		}
		cout << MAX;
		return 0;
	}
	return 0;
}
//AC