#include<bits/stdc++.h>
using namespace std;
char a[1000005];
long long int i,j,d,n,b[15],d1,k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=strlen(a);
	for(i=0;i<=n-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=b[i];j>0;j--)
		{
			cout<<i;
		}
		
	}
	return 0;
}
