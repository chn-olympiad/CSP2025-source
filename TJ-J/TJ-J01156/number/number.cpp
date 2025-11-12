#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=1,a[1000000],maxx=-1,sum=0,p=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'<=9&&s[i]-'0'>=0)
		{
			int u=s[i]-'0';
			a[cnt]=u;
			cnt++;
		}
	}
	int ki=cnt-1;
	for(int j=1;j<=cnt-1;j++)
	{
		for(int i=1;i<=cnt-1;i++)
		{
			if(a[i]>maxx)
			{
				maxx=a[i];
				p=i;
			}
		}
		a[p]=0;
		ki--;
		if(ki==0)
		{
			sum+=maxx;
		}
		else
		{
			sum+=maxx*pow(10,ki);
		}
		maxx=-1;
	}
	cout<<sum;
} 
