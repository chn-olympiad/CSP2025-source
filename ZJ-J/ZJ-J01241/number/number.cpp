#include<bits/stdc++.h>
using namespace std;
string s="";
vector<char>sz;
string ans;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			sz.push_back(s[i]);
		}
	}
	sort(sz.begin(),sz.end(),cmp);
	for(int i=0;i<sz.size();i++){
		if(!(ans=="" && sz[i]=='0')){
			ans+=sz[i];
		}
	}
	if(ans==""){
		ans="0";
	}
	cout << ans;
	return 0;
}