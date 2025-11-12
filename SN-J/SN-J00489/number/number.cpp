#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000]={0};
bool dfs(int x,int y)
{
	return x>y;
}
int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1)
	{
		cout<<s;
	}
	else
	{
		int t=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]-'0'>=0&&s[i]-'0'<=9)
			{
				a[t]=s[i]-'0';
				t++;
			}
		}
		for(int i=0;i<t-1;i++)
		{
			for(int j=i+1;j<t;j++)
			{
				if(a[j]>a[i])
				{
					int x=a[j];
					a[j]=a[i];
					a[i]=x;
				}
			}
		}
		for(int i=0;i<t;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}
