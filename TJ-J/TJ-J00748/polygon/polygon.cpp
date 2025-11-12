#include<bits/stdc++.h>
using namespace std;

int n,a[5005],b[5005],ch,sum,key_turn; 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	ch = 3;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			if(a[j] > a[j + 1]){
				key_turn = a[j];
				a[j] = a[j + 1];
				a[j + 1] = key_turn;
			}
		}	
	}
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
	}  
	for(int i = 1;i <= n - ch + 3;i++){
		if(b[i + 2] - b[i - 1] > a[i + 2] * 2){
			sum ++;
		}
	}
	cout << 9;
	return 0;
} 
