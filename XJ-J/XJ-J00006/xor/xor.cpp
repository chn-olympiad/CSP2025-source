#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,a[100005],k,s,x,f,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(i=1;i<=n;)
	{
		for(j=i;j<=n;j++)
		{
			f=0;
			if(i==j)
			{
				if(a[i]==k)
				{
					i=j+1;
					s++;
					f=1;
					break;
				}
			}
			x=0;
			for(r=i;r<j;r++)
			{
				x+=(a[r]^a[r+1]);
			}
			if(x==k)
			{
				i=j+1;
				f=1;
				s++;
				break;
			}
		}
		if(f==0)
		{
			i++;
		}
	}
	cout<<s;
	return 0;
}

