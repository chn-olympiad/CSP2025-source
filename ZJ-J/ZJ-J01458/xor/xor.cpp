#include<bits/stdc++.h>
using namespace std;
int n,k,v,a[200005],vis[200005]={0},w,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		w=0;
		v=0;
		for(int j=1;j<=n-i+1;j++)
		{
			w=0;
			v=0;
			for(int p=j;p<=min(j+i-1,n);p++)
			if(vis[p]!=0)v=1;
			else w=w^a[p];
			if(w==k&&v==0)
			{
				ans++;
				for(int p=j;p<=j+i-1;p++)
				vis[p]=1;
				v=1;
				cout<<j<<" "<<j+i-1<<endl;
			}
		}
	}
	cout<<ans;
}
