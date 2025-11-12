#include <bits/stdc++.h> 
using namespace std;

string s;
string a;

int main(){
	freopen ("number.in","r");
	freopen ("number.out","w");
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='9') a.push_back('9');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='8') a.push_back('8');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='7') a.push_back('7');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='6') a.push_back('6');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='5') a.push_back('5');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='3') a.push_back('3');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='2') a.push_back('2');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1') a.push_back('1');
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0') a.push_back('0');
	}
	cout<<a;
	fclose("number.in");
	fclose("number.out");
	return 0;
}
