#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll shu[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	for(ll i=0;i<s.size();i++) if('0'<=s[i] && s[i]<='9') shu[s[i]-'0']++;
	for(ll i=9;i>=0;i--) for(ll j=1;j<=shu[i];j++) printf("%lld",i);
	return 0;
} 
