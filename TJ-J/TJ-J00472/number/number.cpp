#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<10) ss+=s[i];
	}
	sort(ss.begin(),ss.end());
	for(long long i=ss.size();i>0;i--) cout<<ss[i-1];
	return 0;
}
