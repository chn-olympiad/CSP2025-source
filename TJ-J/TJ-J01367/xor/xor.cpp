#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
long long yhh[500005];
int tmp[500005];
bool pd[500005][25],pd2[500005][25];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) yhh[i]=a[i]^yhh[i-1];
	for(int o=0;(1<<o)<=k;o++)
	{
		if(k&(1<<o)==0) continue; 
		for(int i=1;i<=n;i++) if(a[i]&(1<<o)==0) pd[i][0]=1;
		for(int i=1;(1<<i)<=n;i++)
		{
			for(int j=n;j-(1<<i)>=0;j--)
			{
				if(pd[j][i-1]&&pd[j-(1<<(i-1))][i-1]) pd[j][i]=1;
			}
		}
		for(int i=0;(1<<i)<=n;i++)
		{
			for(int j=n;j-(1<<i)>=0;j--)
			{
				pd2[j][i]=pd[j][i];
				pd[j][i]=0;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			int mi=21;
			while(mi--)
			{
				if((1<<mi)<=j&&pd[j][mi]) j=j-(1<<mi);
			}
			if((yhh[i]^yhh[j-1])==k)
			{
				tmp[i]=j;
				break;
			}
		}
		//cout<<tmp[i]<<'*';///////////////
	}
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(tmp[i]==0) continue;
		if(tmp[i]>last)
		{
			ans++;
			last=i;
		}
	}
	cout<<ans;
	return 0;
}
