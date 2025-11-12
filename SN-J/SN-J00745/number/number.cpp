#include <bits/stdc++.h>
using namespace std;

vector <char> v;
string s;

bool cmp(char a,char b){
	return a>b;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		
		if('0'<=s[i] && s[i]<='9') v.push_back(s[i]);
		
	}
	
	sort(v.begin(),v.end(),cmp);
	
	if(v[0]=='0') cout<<0;
	else{
		for(int i=0;i<v.size();i++) cout<<v[i];
	}
	
	return 0;
	
}
