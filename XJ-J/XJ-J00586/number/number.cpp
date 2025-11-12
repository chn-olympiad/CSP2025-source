#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	int a[s.length()];
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[j]=int(s[i])-48;
			j++;
		}
	}
	for(int q=9;q>=0;q--){
		for(int i=1;i<j;i++){
			if(a[i]==q){
				cout<<a[i];
			}
		}
	}
	return 0;
} 
