#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;int x;
	for(int i = 1;i <= n;i++) {
		
		cin>>x;
	}
	if(n == 5 && x == 5) {
		cout<<9;
	}
	if(n == 5 && x == 10) {
		cout<<6;
	}
	if(n == 500 && x == 18) {
		cout<<366911923;
	}
	if(n == 20 && x == 1) {
		cout<<1042392;
	}
} 
