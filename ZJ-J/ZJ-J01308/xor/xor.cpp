#include<bits/stdc++.h>
using namespace std;
const int Sizn=1<<20|1;
int vis[Sizn],a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=a[i-1]^x;
	}
	vis[0]=n+1;
	int flag=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]^k^cnt]>=flag)
		{
			ans++;
			flag=i+1;
			cnt=a[i];
			continue;
		}
		vis[a[i]^cnt]=max(vis[a[i]^cnt],i);
	}
	cout<<ans<<endl;
	return 0;
}

