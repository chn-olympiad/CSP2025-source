#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i-1]>='0'&&s[i-1]<='9')
		{
			a[++cnt]=s[i-1]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=cnt;i>=1;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}
