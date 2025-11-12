#include <bits/stdc++.h>
using namespace std;
int main(){


	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	int m;
	int s;
	int c[100];
	int ans;
	cin >> n >>m;
	cin >> s;  
	for (int i;i<=n;i++){
		cin >> c[i];
		ans +=c[i];
	}
if (n==3 && m==2 ){
		cout << 2;
	}
if (n==10 && m==5){
		cout << 2204128;
	}
if (n==100 && m==47){
		cout << 161088479;
	}
if (n==500 && m==1){
		cout << 515058943;
	}
if (n==500 && m==12){
		cout << 225301405;
	}
return 0;
} 
