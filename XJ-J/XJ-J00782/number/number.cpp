#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	int maxx=-1,cnt=0;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	} 
	return 0;
}
