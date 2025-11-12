#include<bits/stdc++.h>
using namespace std;
int rp=INT_MAX;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char i='9';i>='0';i--){
		for(int j=0;j<s.size();j++){
			if(s[j]==i) cout<<s[j];
		}
	}
	
	return 0;
}
