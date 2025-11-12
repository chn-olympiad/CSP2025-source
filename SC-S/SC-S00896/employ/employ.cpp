#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510];
long long h;
char s[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{	
		if(a[i]=='0')
		{
			break;
		}
		else
		{
			if(i==l-1)
			{
				
			}
		}
	}
	if(m==1)
	{
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{	
			if(s[i]=='1')
			{
				l=i;
				for(int j=1;j<=n;j++)
				{	
					if(l<a[j])
					{
						h++;
						h=h%998244353;
					}
				}
			}
		}
	}
	if(m==n)
	{
		int l=strlen(s);
		for(int i=1;i<=n;i++)
		{	
			for(int j=0;j<l;j++)
			{
				if(s[j]=='1'&&j-b[j]+1<a[i])
				{
					b[j]-=1;
					h++;
					s[i]=0;
				}
			} 
		}
	}
	cout<<h;
	return 0;
}