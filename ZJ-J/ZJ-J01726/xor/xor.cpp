#include<bits/stdc++.h>
using namespace std;
int n,k,lastx=0,tmp,cnt=0,idx,maxn=0;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
	}
	else
	{
		while(lastx<n)
		{
			for(int i=lastx+1;i<=n;i++)
			{
				if(i==lastx+1) tmp=a[i];
				else tmp^=a[i];
				if(tmp==k)
				{
					cnt++;
					idx=i;
					break;
				}
			}
			if(tmp!=k) lastx++;
			else lastx=idx;
		}
	}
	cout<<cnt;
	return 0;
}
