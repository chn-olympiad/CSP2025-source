#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int i,j,n,x=0,m,y=0,ans=0,z,q=0;
	char s[1000],c[600];
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	c[i]=i+'0';
	for(i=0;i<strlen(s);i++)
	{
	if(s[i]=='1')
	x++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>z;
		if(z==0)
		q++;
	}
	if(x==strlen(s))
	{
		if(m!=(n-q))
		{
		cout<<0;
		return 0;
	}
		else
		do
		{
			ans++;
		}
		while(next_permutation(c+1,c+1+n));
	}
	cout<<ans;
	return 0;
}
