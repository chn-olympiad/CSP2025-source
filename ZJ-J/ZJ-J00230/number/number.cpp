#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
string s;
int a[1000005],x;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++x]=s[i]-48;
		}
	}
	sort(a+1,a+x+1);
	if(a[x]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=x;i>=1;i--)
	{
		cout<<a[i];
	}
}
