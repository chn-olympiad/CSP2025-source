#include <bits/stdc++.h> 
using namespace std;

long long a[120];
string s;

int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","r",stdout);
	
	cin >> s;
	for(int i=0; i<=s.size(); i++){
		if(a[i] >='0' && a[i]<='9'){
			a[(a[i]-'0')]++;
		}
	}
	for(int i=9; i>=0; i--){
		for(int j=0; j<a[i]; j++){
			printf("%d",i);
		}
	}
	
return 0;
}
