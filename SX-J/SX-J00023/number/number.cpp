#include<bits/stdc++.h>
using namespace std;
	long long bl;
	long long b[1000000];
	char a[1000000];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	long long l=strlen(a);
	for(long long i=0;i<l;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
   			b[bl]=a[i]-'0';
			bl++;
		}
	}
	for(long long i=0;i<bl;i++)
	{
		for(long long j=i;j<bl;j++)
		{
			if(b[i]<b[j])
			{
				int t;
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(long long j=0;j<bl;j++)
	{
		cout<<b[j];
	}
	return 0;
}