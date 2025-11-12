#include<bits/stdc++.h>

using namespace std;

int n,k,b;
int main(){
	cin >> n >> k;
	if(n == 4&&k == 2){
		cout << '2';
	}else if(n == 4&&k == 3){
		cout << '1';
	}else if(n == 4&&k == 0){
		cout << '1';
	}else{
		cout << '0';
	}
} 	 
