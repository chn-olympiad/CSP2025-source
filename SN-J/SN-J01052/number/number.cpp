#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<char> s2;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9')s2.push_back(s[i]);
	}
	sort(s2.begin(),s2.end(),cmp);
	for(int j=0;j<s2.size();++j)cout<<s2[j];
	return 0;
}
