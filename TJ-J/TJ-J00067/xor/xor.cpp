#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	vector<int> a(n+1);
	int b,c,d;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	if (k == 0){
		for (int i = 0; i < n; i++){
			if (a[i] == 0){
				ans++;
			}
		}
	}
	if (k==1){
		for (int i = 0; i < n; i++){
			if (a[i] == 1){
				ans++;
			}
			else if (a[i] == 0 && a[i+1] == 0){
				ans++;
				i+=1;
			}
		}
	}
	cout << ans;
	return 0;
}
