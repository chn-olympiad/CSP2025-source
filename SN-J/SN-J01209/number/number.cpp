#include <bits/stdc++.h>
using namespace std;
string s,num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for (int i=0;i<len;i++){
		if (isdigit(s[i])) num+=s[i];
	}
	sort(num.begin(),num.end(),greater<char> ());
	cout<<num;
	return 0;
}

