#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],sum[500005];
int num=0,ans=0;
typedef struct
{
	int start,end;
}Toge;
Toge toge[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int t=sum[j]^sum[i-1];
			if(t==k)
			{
				toge[++num].start=i;
				toge[num].end=j;
			}
		}
	}
	int i=1,j=2,ans=0;
	while(j<=num)
	{
		int s1=toge[i].start,e1=toge[i].end,s2=toge[j].start,e2=toge[j].end;
		if((s2>=s1&&s2<=e1)||(e2>=s1&&e2<=e1))
		{
			ans++;
		}
		else
		{
			i=j;
		}
		j++;
	}
	cout<<num-ans;
	return 0;
}