#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,n,k,s=0;
	cin>>n>>k;
	cin>>a[1];
	b[1]=a[1];
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			s++;
			continue;
		}
		for(j=i+1;j<=n;j++)
		{
			if(b[i-1]^b[j]==k)
			{
				s++;
				i=j;
				break;	
			}		
		}
	
	}
	cout<<s;
	return 0;
}
