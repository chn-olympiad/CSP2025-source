#include<bits/stdc++.h>
using namespace std;
struct note
{
	string s1,s2;
}a[200050];
struct node
{
	string s1,s2;
}s[200050];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	/*for(int k=1;k<=q;k++)
	{
		int cnt=0;
		string s1="";
		string s2="";
		for(int x=0;x<s[k].s1.size();x++)
		{
			for(int z=0;z<s[k].s1.size();z++)
			{
				for(int i=x;i<z;i++)
				{
					s1+=s[k].s1[i];
					s2+=s[k].s2[i];
					for(int i=1;i<=n;i++)
					{
						if(a[i].s1==s1&&a[i].s2==s2)
						{
							cnt++;
						}
					}
				}
			}
		}		
		cout<<cnt<<endl;
	}*/
	bool flag1=false;
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		int cnt=0;
		for(int j=0;j<a[i].s1.size();j++)
		{
			if(a[i].s1[j]!='a'&&a[i].s1[j]!='b'||cnt>1)
			{
				flag=false;
				break;
			}
			else
			{
				if(a[i].s1[j]=='b')
				{
					cnt++;
				}
			}
		}
		if(flag==true)
		{
			flag1=true;
		}
	}
	if(flag1==true)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
