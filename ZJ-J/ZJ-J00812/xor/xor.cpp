#include<bits/stdc++.h>
using namespace std;
struct Node{
	int next;
}o[500010];
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m,ans=0,l,r;
	bool b=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(l=1;l<=n-i+1;l++)
		{
			if(a[l]==-1)
			{
				l=o[l-1].next;
			}
			m=a[l];
			for(int j=l+1;j<=l+i-1;j++)
			{
				if(a[j]!=-1)
					m^=a[j];
				else
				{
					b=0;
					break;
				}
			}
			if(b==0)
				break;
			if(b)
				if(m==k)
				{
					ans++;
					for(int j=l;j<=l+i-1;j++)
						a[j]=-1;
					o[l-1].next=l+i;
					l=l+i-1;
				}
			b=1;
		}
	}
	cout<<ans;
	return 0;
}
