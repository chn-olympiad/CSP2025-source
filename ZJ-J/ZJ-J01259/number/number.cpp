#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	map<char,int> mp;
	for(ll i=0;i<s.size();i++){
		mp[s[i]]=mp[s[i]]+1;
	}
	
	for(ll i=9;i>=0;i--){
		for(ll j=0;j<mp[char(i+48)];j++)cout<<i;
	}
	cout<<endl;
	return 0;
}