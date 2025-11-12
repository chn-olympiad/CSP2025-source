#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ma,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	if(ma==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(k==0)
					sum++;
				continue;
			}
			int j=i;
			while(a[j]==1&&j<=n)
				j++;
			int cnt=j-i;
			i=j-1;
			if(k==0)	sum+=cnt/2;
			else		sum+=cnt;
		}
	}
	printf("%d",sum);
	return 0;
}
//选取非重叠区间进行连续异或,使每个区间的异或值均为k
//在满足上述要求的情况下让区间数量尽可能多
//让满足条件的区间长度尽可能短 
//O(nlogn)
//
