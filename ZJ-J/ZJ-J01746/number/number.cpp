#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> x;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') x.push_back(s[i]-'0');
	}
	sort(x.begin(),x.end(),greater<int>());
	for(int i=0;i<x.size();i++) cout<<x[i];
	return 0;
}
