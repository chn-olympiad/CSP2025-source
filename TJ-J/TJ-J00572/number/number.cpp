#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	cout<<s1;
	return 0;
}
