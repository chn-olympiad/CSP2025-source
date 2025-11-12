#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	vector<int>a;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
