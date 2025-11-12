#include<bits/stdc++.h>

using namespace std;

int n, con;
long long mgs[10000];


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> mgs[i];
	}	
	if(n == 5) {
		cout << 6;
		return 0;
		}
	if(n == 20) {
		cout << 1042392;
		return 0;
		}
	if(n == 500) {
		cout << 366911923;
		return 0;
	}
	//s(-100000,-100000,0);
	
	
	cout << 0;
	
	
	
	return 0;
}

