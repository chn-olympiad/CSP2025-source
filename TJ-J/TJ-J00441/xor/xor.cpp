#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;

int main(){
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int al = sizeof(a) / 4;
	int t[(1 << al) + 1];
	int nt[(1 << al) + 1];
	int num[al];
	
	for(int i = 0; i < (1 << (al-1)); i++){
		int x = i, j = 0;
		while(x > 0){
			if(x&1){
				t[j] = 1;
			}else{
				t[j] = 0;
			}
			x >>= 1;
			j++;
		}
		int d = 0;
		for(int l = j; l >= 0; l--){
			if(t[l] == 1) nt[d++] = l;
		}
		for(int l = 0; l < sizeof(nt) / 4; l++){
			int tn = 0;
			for(int c = nt[l]; c <= nt[l+1]; c++){
				tn ^= a[c];
			}
			if(tn == k) cnt++;
		}
	}
	
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
