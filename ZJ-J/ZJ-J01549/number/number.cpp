#include<bits/stdc++.h>
using namespace std;
string s;
long long num[10],len,ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans++;
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
