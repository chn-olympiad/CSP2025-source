#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
int del[200005];
int couldp1[200005],couldp2[200005],couldq1[200005],couldq2[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int p1,p2;
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]=='b')
			{
				p1=j;
				couldp1[i]=j;
				couldp2[i]=s1.size()-j;
				break;
			}
		}
		for(int j=0;j<s2.size();j++)
		{
			if(s2[j]=='b')
			{
				couldq1[i]=j;
				couldq2[i]=s2.size()-j;
				p2=j;
				break;
			}
		}
		del[i]=p1-p2;
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int p1,p2;
		int canp1,canp2,canq1,canq2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]=='b')
			{
				p1=i;
				canp1=i;
				canp2=t1.size()-i;
				break;
			}
		}
		for(int i=0;i<t2.size();i++)
		{
			if(t2[i]=='b')
			{
				p2=i;
				canq1=i;
				canq2=t2.size()-i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(del[i]==p1-p2 && canp1>=couldp1[i] && canp2>=couldp2[i] && canq1>=couldq1[i] && canq2>=couldq2[i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
