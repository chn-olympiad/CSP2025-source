#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int b=9;b>=0;b--){
		for(int c=0;c<a.length();c++){
			if(a[c]-'0'==b) cout<<a[c]-'0';
		}
	}
	return 0;
} 

