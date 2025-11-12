#include<bits/stdc++.h>
using namespace std;
int f,l,a[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(!f&&i==0)
		{
			cout<<0;
			break;
		}
		while(a[i])
		{
			f=1;
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
