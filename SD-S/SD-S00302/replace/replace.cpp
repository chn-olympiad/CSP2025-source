#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1;
string s2;
int b;
int lft[200005][505][2];
int rit[200005][505][2];
int visl[200005];
int visr[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=0;j<s1.length();j++)
		{
			if(s1[j]=='b')
			{
				b=j;
				break;
			}
		}
		for(int j=0;j<s2.length();j++)
		{
			if(s2[j]=='b')
			{
				if(b<j)
				{
					rit[j-b][++visr[j-b]][0]=b;
					rit[j-b][visr[j-b]][1]=s2.length()-j-1;
				}
				else
				{
					lft[b-j][++visl[b-j]][0]=j;
					lft[b-j][visl[b-j]][1]=s1.length()-b-1;
				}
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<s1.length();j++)
		{
			if(s1[j]=='b')
			{
				b=j;
				break;
			}
		}
		for(int j=0;j<s2.length();j++)
		{
			if(s2[j]=='b')
			{
				if(b<j)
				{
					int ans=0;
					for(int k=1;k<=visr[j-b];k++)
					{
						if(rit[j-b][k][0]<=b&&rit[j-b][k][1]<=s2.length()-j-1)
						{
							ans++;
						}
					}
					cout<<ans<<endl;
				}
				else
				{
					int ans=0;
					for(int k=1;k<=visl[b-j];k++)
					{
						if(lft[b-j][k][0]<=j&&lft[b-j][k][1]<=s1.length()-b-1)
						{
							ans++;
						}
					}
					cout<<ans<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
