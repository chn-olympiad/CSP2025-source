#include<bits/stdc++.h>
using namespace std;
long long a[500009],n,k,cnt,d,j;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s:; 
		d=a[i];
		for(j=i+1;j<=n;j++)
		{
			if(d==k)
			{
				i=j;
				cnt++;
				goto s;
			}
			d^=a[j];
		}
		if(d==k)
		{
			cnt++;
			i=j;
		}
	}
	cout<<cnt;
	return 0;
}
