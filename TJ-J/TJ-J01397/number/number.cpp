#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string sz;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz+=s[i];
		}
	}
	sort(sz.begin(),sz.end());
	for(int i=sz.size()-1;i>=0;i--){
		cout<<sz[i];
	}
	return 0;
} 
