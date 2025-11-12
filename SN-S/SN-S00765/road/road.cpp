#include<bits/stdc++.h>
using namespace std;
long long n,m,T,a1[100005],a2[100005],a3[100005],f[100800],vis[1005][1005],h[100008];
long long ans,cnt;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		cin>>a1[i]>>a2[i]>>a3[i];
		f[i]=a3[i];
			
	}
	for(int i=1;i<=m;i++)
	for(int j=1;i<=n+1;i++)
	cin>>h[i];
	sort(f+1,f+1+n);
		for(int j=m;j>=1;j--)
		{
			
			ans+=f[j];	cnt++;
			if(cnt==T)
			{
				break;
			}
		
		}	
	cout<<ans;
	return 0;
}

