#include<bits/stdc++.h>
using namespace std;
char c[1000005],cb[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,i,j,k;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			cb[i]=c[i];
		}
		sort(cb+1,cb+n+1);
	}
	for(i=1;i<=n;i++)
	{
		cout<<cb[i];
	}
	return 0;
}
