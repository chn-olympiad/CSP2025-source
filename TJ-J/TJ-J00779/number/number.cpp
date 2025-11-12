#include<bits/stdc++.h>
using namespace std;
string out;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int o[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			o[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<o[i];j++){
			out+=i+'0';
		}
	}
	cout<<out;
	return 0;
} 
