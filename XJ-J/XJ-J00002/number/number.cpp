#include <bits/stdc++.h>
using namespace std;
string a;
int b[10];
int main (){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for (long long i=0;i<=a.size();i++){
		if (a[i]>='0' && a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=b[i];j++){
			cout<<char(i+'0');
		}
		
	}
	
	
	return 0;
} 
