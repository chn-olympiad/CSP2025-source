#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int n,k,A[N],pre[N],lst[N],f[N][N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		pre[i]=pre[i-1]^A[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((pre[j]^pre[i-1])==k)
			{
				lst[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(lst[i]==0)
			continue;
		f[i][lst[i]]=1;
		for(int j=1;j<i;j++)
		{
			for(int k=j;k<i;k++)
			{
				f[i][lst[i]]=max(f[i][lst[i]],f[j][k]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans=max(ans,f[i][j]);
		}
	}
	cout <<ans<<endl;
	return 0;
}
