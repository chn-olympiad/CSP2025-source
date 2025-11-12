#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string q1[200005],q2[200005];
bool check(string x,string y,string a,string b)
{
	string tmp=x;
	int i=0;
	int flag=0;
	while(i<x.length())
	{
		if((a[0]==x[i])&&(flag==0))
		{
			flag==1;
		}
		if(flag>0)
		{
			if(flag==a.length())
			{
				if(tmp==y)
				{
					return 1;
				}
				else
				{
					flag=0;
					tmp=x;
				}
			}
			else
			{
				tmp[i]=b[flag-1];
				if(tmp[i]!=y[i])
				{
					flag=0;
					tmp=x;
				}
			}
			flag++;
		}
		i++;
    }
    return 0;
}
long long res;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=q;i++)
	{
		res=0;
		for(int j=1;j<=n;j++)
		{
		    res+=check(s1[j],s2[j],q1[i],q2[i]);
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
