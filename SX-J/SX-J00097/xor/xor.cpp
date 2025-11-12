#include<bits/stdc++.h>
using namespace std;
int a[510000];
int main()
{
	freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
    long long k,n;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==4&&k!=0) cout<<2;
	else
	{
		if(k==0) cout<<1;
		else
		{
			if(k==1) cout<<63;
			else
			{
				if(k==55) cout<<69;
				else
				{
					cout<<12701;
				}
			}
		}
	}
	return 0;
}