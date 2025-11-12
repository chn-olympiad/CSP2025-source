#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int j=9;j>=0;j--){
		for(int i=0;i<s.size();i++){
			if(s[i]-'0'==j){
				cout<<s[i];
			}
		}
	}
	return 0;
}
