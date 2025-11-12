#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int a[N];
bool b[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{	
			int t=0,flag=0;
			for(int s=i;s<=j;s++)
			{
				t=t xor a[s];
			}
			if(t==k)
			{
				for(int s=i;s<=j;s++)
				{
					if(b[s])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					cnt++;
					for(int s=i;s<=j;s++)
					{
						b[s]=1;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
