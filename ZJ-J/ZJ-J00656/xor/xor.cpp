#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans,left1[5000001],right1[5000001],cnt,sum,ff;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)
		{
			ans++;
			left1[ans]=i;
			right1[ans]=i;
		}
		else 
		{
			cnt=a[i];
			for(int j=i+1;j<=n;j++)
			{
				cnt^=a[j];
				if(cnt==m)
				{
					ans++;
					left1[ans]=i;
					right1[ans]=j;
				}
			}
		}
	}
	for(int i=1;i<=ans;i++)
	{
		for(int j=i+1;j<=ans;j++)
		{
			if(right1[i]>right1[j]||right1[i]==right1[j]&&left1[i]>left1[j])
			{
				swap(left1[i],left1[j]);
				swap(right1[i],right1[j]);
			}
		}
	}
	sum++;ff=1;
	for(int i=1;i<=ans;i++)
	{
		if(left1[i]>right1[ff])
		{
			sum++;
			ff=i;
		}
	}
	cout<<sum;
	return 0;
}
