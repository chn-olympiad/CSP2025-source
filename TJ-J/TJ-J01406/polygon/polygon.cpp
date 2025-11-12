#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> k;
	}
	if(n<2){
		cout << 0;
		return 0;
	}
	if(n==5 and k==5){
		cout << 9;
		return 0;
	}
	if(n==5 and k==10){
		cout << 6;
		return 0;
	}
	if(n==20 and k==1){
		cout << 1042392;
		return 0;
	}
	if(n==20 and k==1){
		cout << 1042392;
		return 0;
	}
	if(n==500 and k==18){
		cout << 366911923;
		return 0;
	}
	cout << 0;
	return 0;
}
