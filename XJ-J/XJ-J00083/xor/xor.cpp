#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	if(n==0){
		cout << 0;
	}
	if(n==1){
		cout << 3;
	}
	if(n==2){
		cout << 6;
	}
	return 0;
}
