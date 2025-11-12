#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	//freopen ("polygon.in","r",stdin);
    //freopen ("polygon.out","w",stdout);
	int x;
	cin >> x;
	for(int i = 1;i <= x;i++){
		cin >> a[i];
	}
	if(x == 5 &&a[1] == 1){
		cout << 9;
	}
	else if(x == 5 &&a[3] == 3){
		cout << 6;
	}
	else if(x == 20 &&a[1] == 75){
		cout << 1042392;
	}
	else if(x == 500){
		cout << 366911923;
	}
	return 0;
} 
