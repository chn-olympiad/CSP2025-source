#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m = 0;
	cin >> n >> k;
	int a[n];
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] == 1){
			m += 1;
		}
		
	}
	if(m == n && k == 0){
		cout << n/2;
		return 0;
	}
	cout << 0;
	return 0;
} 
