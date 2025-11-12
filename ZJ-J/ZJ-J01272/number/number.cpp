#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000050],cnt;
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for (int i=0;i<len;i++)
	{
		if (s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-48;
	}
	sort (a+1,a+1+cnt);
	bool fl=true;
	for (int i=1;i<=cnt;i++)
		if (a[i]!=0)
		{
			fl=false;
			break;
		}
	if (fl==true)
	{
		cout<<0;
		return 0;
	}
	for (int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	} 
	return 0;
}