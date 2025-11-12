#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
Int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char tmp;
	while(cin >> tmp){
		if('0' <= tmp && tmp <= '9'){
			a[tmp-'0'] ++;
		}
	}
	for(Int i = 9; i >= 0; i --){
		while(a[i] > 0){
			printf("%lld",i);
			a[i] --;
		}
	}
	return 0;
}

