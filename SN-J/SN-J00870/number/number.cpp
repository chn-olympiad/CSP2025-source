#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			n++;
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>-1;i--)
	{
		j++;
		if(j<=n)
		{
			cout<<a[i];
		}
	}
	return 0; 
}
