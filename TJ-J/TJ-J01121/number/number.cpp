#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],tot,cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			cnt++;
		}
		else
		    if(s[i]<='9'&&s[i]>='1')
		    {
		    	a[tot++]=s[i]-'0';
			}
	}
	sort(a,a+tot,cmp);
	for(int i=0;i<tot;i++)
	{
		cout<<a[i];
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<0;
	}
	return 0;
}
