#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int>k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			k[s[i]]++;
	for(char i='9';i>='0';i--)
		while(k[i]--)
			cout<<i;
	return 0;
}
