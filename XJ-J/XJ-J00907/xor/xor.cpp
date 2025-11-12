#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin >> n >> k;
	vector<int>a(n);
	int sum = 0;
	for(int i = 0;i <n;i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum == n){
		cout << n/2;
		return 0;
	}
	int cnt = 0;
	if(sum < n){
		for(int i = 0;i <n;i++)if(a[i] == 1)cnt++;
		if(k == 1) {
			cout << cnt;
			return 0;
		}
		else {
			cout <<n-cnt;
			return 0;
		}
	}
	int maxl = 0;
	for(int i = 0;i < n;i++){
		int lk = a[i];
		int cntl = 0;
		for(int j = i+1;j <n;j++){
			lk ^= a[j];
			if(lk == k){
				cntl++;
				lk = a[j+1];
				j++;
			}
		}	
		if(maxl < cntl)maxl = cntl;
	}
	int cntx = 0;
	for(int i = 0;i < n;i++){
		if(a[i] == k) cntx ++;
	}
	cout << max(maxl,cntx);
	return 0;
}
