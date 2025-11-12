#include<bits/stdc++.h>
using namespace std;
int a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	if (a<10) {
		cout << a;
		return 0;
	}
	if (a>10){
		if(a/10 > a%10)
		cout << (a/10) << (a%10);
		else
		cout << (a%10) << (a/10);
		return 0;
	}
}
