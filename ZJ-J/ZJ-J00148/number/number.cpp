#include<bits/stdc++.h>
using namespace std;
string s;
int t[15],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')t[s[i]-48]++;
	for(int i=9;i>=0;i--)while(t[i]--)cout<<i;
	return 0;
}