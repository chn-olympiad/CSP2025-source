#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long int n,k,ans;
long long int arr[N];
bool flag[N],pd=0;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==0)
	{
		for(int a=1;a<=n;a++)
		{
			scanf("%d",&arr[a]);
			if(arr[a]==k)
			{
				ans++;
			}
		}
		printf("%d",ans);
		return 0;
	} 
	for(int a=1;a<=n;a++)
	{
		scanf("%d",&arr[a]);
		if(arr[a]==k)
		{
			ans++;
			flag[a]=1;
		}
		if(arr[a]==0)
		{
			flag[a]=1;
		}
		arr[a]^=arr[a-1];
		if(arr[a]==k&&flag[a]==0)
		{
			ans++;
		}
	}
	printf("%d",ans);
	
	
	return 0;
} 
