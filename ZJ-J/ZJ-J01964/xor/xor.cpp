#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,k,a[N],pre[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		for(int t=j;t<=i;t++)
		{
			if(((pre[i]^pre[t-1])==k&&i!=t)||a[i]==k)
			{
				j=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
