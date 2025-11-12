#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
string s,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=9;i++){
		char c=(char)(i+'0');
		mp[c]=0;
	}
	for(int i=0;i<len;i++){
		mp[s[i]]++;
	}
	for(int i=9;i>=0;i--){
		char c=(char)(i+'0');
		for(int j=1;j<=mp[c];j++){
			cout<<i;
		}
	}
	return 0;
}
