#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{	
		if (s[i]>='0' && s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+N);
	for (int i=N;i>=0;i--)
	{
		if (a[i]!=-1)
		{
			cout<<a[i];
		}
	}
	return 0;
}
