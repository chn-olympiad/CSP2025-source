#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int j=9;j>=0;j--){
		for(int i=0;i<s.size();i++){
			if(s[i]==j+'0'){
				a+=s[i];
			}
		}		
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}

