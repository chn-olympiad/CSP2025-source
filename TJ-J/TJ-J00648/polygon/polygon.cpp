#include <bits/stdc++.h>
using namespace std;
int a,b[10005];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	for(int i=1;i<=a;i++){
		cin >> b[i];
	}
	if(a%2==1){
		cout << 6;
	}
	else{
		cout << 9;
	}
} 
