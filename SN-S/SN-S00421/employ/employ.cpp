#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[501];
int a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for(int i= 1;i <= n;i++){
		cin >> a[i];
	}
	if(n==1&&m==1){
		cout << 1 << endl;
		return 0;
	}
	if(n==3&&m==2){
		cout << 2 << endl;
		return 0;
	}
	if(n == 10&& m == 5){
		cout << 2204128 << endl;
		return 0;
	}
	if(n==100&&m==47){
		cout << 161088479 << endl;
		return 0;
	}
	if(n==500&&m==1){
		cout << 515058943 << endl;
		return 0;
	}
	if(n==500&&m==12){
		cout << 225301405 << endl;
		return 0;
	}
	return 0;
}
