#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	vector<int> v;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9)
			v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end(),greater<int>());
	for(unsigned long long i=0;i<v.size();i++)
		cout<<v[i];
	return 0;
}
