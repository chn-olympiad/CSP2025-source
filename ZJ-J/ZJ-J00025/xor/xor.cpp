#include<bits/stdc++.h>
using namespace std;
int cnt,sum,n,k,a[500010];
bool flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)     flag = 0;
	}
	if(k==0 && flag==1)
	{
		printf("%d",n/2);
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		sum = a[i];
		for(int j = i+1; j <= n; j++)
		{
			sum ^= a[j];
			if(sum==k)
			{
				cnt++;
				i = j;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
