#include <bits/stdc++.h>
using namespace std;
multiset<char>st;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')st.insert(s[i]);
	}
	s="";
	for(auto it=st.begin();it!=st.end();it++){
		s=*it+s;
	}
	cout<<s;
	return 0;
}
