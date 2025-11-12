#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string s1="";
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			s1.push_back(s[i]);
		}
	}
	sort(s1.begin(),s1.end(),greater<char>());
	cout<<s1;
	return 0;
}