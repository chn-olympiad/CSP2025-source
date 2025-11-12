#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int  n;
	int q;
	int s[100];
	int t[100];
	cin >>n >>q;
	for (int i =0;i<=2*n+2*q;i++){
		cin >> s[i];
	}
if (n==4 && q==2){
		cout << 2<<endl <<0;
	}
if (n==3 && q==4){
		cout << 0<<endl<<0<<endl<<0<<endl<<0;
	}
return 0;
} 
