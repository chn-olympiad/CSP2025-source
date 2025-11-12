#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool lin=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && '0'<=s[i]){
			if(s[i]!='0') lin=1;
			str.push_back(s[i]);
		}
	}
	sort(str.begin(),str.end());
	if(lin)
		for(int i=str.size()-1;i>=0;i--)
			cout<<str[i];
	else
		cout<<0;
	return 0;
}
