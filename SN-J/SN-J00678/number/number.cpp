//SN-J00678 ¶ÎÑÅçÍ ¸¨ÂÖÖĞÑ§   
#include<bits/stdc++.h>
using namespace std;
string s;
int o[11];
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			o[s[i]-'0']++;
		}
	}
	ans="";
	for(int j=1;j<=o[9];j++){
		ans+='9';
	}
	for(int j=1;j<=o[8];j++){
		ans+='8';
	}
	for(int j=1;j<=o[7];j++){
		ans+='7';
	}
	for(int j=1;j<=o[6];j++){
		ans+='6';
	}
	for(int j=1;j<=o[5];j++){
		ans+='5';
	}
	for(int j=1;j<=o[4];j++){
		ans+='4';
	}
	for(int j=1;j<=o[3];j++){
		ans+='3';
	}
	for(int j=1;j<=o[2];j++){
		ans+='2';
	}
	for(int j=1;j<=o[1];j++){
		ans+='1';
	}
	for(int j=1;j<=o[0];j++){
		ans+='0';
	}
	cout<<ans;
	return 0;
}

