#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,k=0,maxnn=0;
string s;
int main()
{
	//freopen("number.in",stdin);
	//freopen("number.out",stdout);
	cin>>s;
	n=s.size();
	k=0;
	for(j=1;j<=n;j++)
	{
		if(s[i]>='0'&&s[i]<='9')
		k++;
	} 
	 
	for(j=1;j<=k;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				if(s[i]-'0'>=maxnn)
				{
				maxnn=s[i]-'0';
				s[i]='0';
				}
			}
		}
		cout<<maxnn;
	}
 } 
