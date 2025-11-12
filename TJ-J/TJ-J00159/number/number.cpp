#include<bits/stdc++.h>//number
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,str;
	cin>>s;
	int ai=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			str=str+s[i];
		}
	}
	sort(str.begin(),str.end());
	for(int i=str.size()-1;i>=0;i--){
		cout<<str[i];
	}
	return 0;
}
