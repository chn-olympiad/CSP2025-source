#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n[10];
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string a;
	cin >> a;
	for(int i = 0; i < a.length(); i ++){
		if(a[i] <= '9' && a[i] >= '0'){
			n[a[i] - '0'] ++;
		}
	}
	for(int i = 9; i >= 0; i --){
		for(int j = 1; j <= n[i]; j ++){
			cout << i;
		}
	}
	return 0;
}
