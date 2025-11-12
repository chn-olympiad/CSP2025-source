#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+10,M=2<<21;
int n,ans,a[N],s[N],l=0,g,k;
int vis[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=0;i<M-5;i++)
	{
		vis[i]=INT_MIN;
	}
	vis[0]=0;
	for(int i=1;i<=n;i++)
	{
		g=k^s[i];
		if(vis[g]>=l) ans++,l=i;
		vis[s[i]]=i;
	}
	cout<<ans;
	return 0;
}