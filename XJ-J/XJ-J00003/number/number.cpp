#include<bits/stdc++.h>
using namespace std;
int a[1000005]={0},t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			t++;
			a[t]=int(s[i]-'0');
			
		}
	}
	sort(a+1,a+t+1);
	if(a[t]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=t;i>=1;i--)
	{
		cout<<a[i];
	}
}
