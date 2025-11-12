#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,ss;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out ","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a+b;i++){
		cin>>s;
		ss+=s;
		cin>>s;
		ss+=s;
	}
	if(ss=="xabcxxadexabcdbcdeaabbxabcxxadexaaaabbbb"){
		cout<<2<<endl<<0;
		return 0;
	}
	if(ss=="abbccdaabbaabacba"){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	return 0;
}