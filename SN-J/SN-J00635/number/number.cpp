#include <bits/stdc++.h>
using namespace std;

long long a[15];

int main(){
	#ifndef MDEBUG
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	string s;
	cin >> s;
	for(char i : s){
		if(isdigit(i)){
			a[i-'0']++;
		} 
	}
	for(int i = 9;i >= 0;--i){
		while(a[i]>0){
			cout << i;
			--a[i];
		}
	}
}
