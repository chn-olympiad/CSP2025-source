#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;int t[105],z;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	for(int i=9;i>=1;i--)
	{
		if(t[i]>0) z=1;
		for(int j=1;j<=t[i];j++) cout<<i;
	}
	if(z==1) for(int j=1;j<=t[0];j++) cout<<0;
	else cout<<0;
	return 0;
}