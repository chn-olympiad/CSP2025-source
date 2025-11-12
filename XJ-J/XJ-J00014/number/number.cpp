#include<bits/stdc++.h> 
using namespace std;
int num[10005],a[10005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	int maxn=0,i,j;
	cin>>s;
	int l=s.size();
	for(i=0;i<=l-1;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			num[s[i]-48]++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}
		
	}
	return 0;
}
