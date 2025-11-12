#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int len;
int k[15];
string ans;
signed main(void)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
			k[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=k[i];j++)
			ans=ans+char(i+'0');
	cout<<ans;
	return 0;//完结撒花
}