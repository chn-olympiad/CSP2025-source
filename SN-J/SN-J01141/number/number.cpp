#include<bits/stdc++.h>
using namespace std;
int s[10000];
int main()
{
	int n,a=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]<=s[i+1])
			{
				a=s[i+1];
				s[i+1]=s[i];
				s[i]=a;
			}	
		}
	}
	s[0]=n;
	for(int i=1;i<=n;i++)
	{
		cout<<s[i];
	}
}
