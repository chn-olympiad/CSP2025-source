#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000010],a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long k=1,l=1,ss=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')b[k]=s[i]-'0',k++;
	}
	k--;
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(b[j]==i)a[l]=i,l++;
		}
	}
	l--;
	for(int i=1;i<=l;i++)if(a[i]==0)ss++;
	if(ss==l)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=l;i++)cout<<a[i];
	return 0;
}