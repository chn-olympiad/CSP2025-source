#include<bits/stdc++.h>
using namespace std;
string s;
long long len=0,f=0,a[1000090],ans=0;
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
			f++;
			a[f]=s[i]-'0';
		}
	}
	sort(a+1,a+f+1);
	for(int i=f;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
