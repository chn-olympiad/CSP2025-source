#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005][10005],c[10005],q1,q2,ans=200000000000,uuz;
long long cs[11][10005];
bool b[10005][10005];
int dfs(int x,long long z)
{
	int op=0;
	for(int q=1;q<=n;q++)
	{
		if(b[x][q]==1)
		{
			if(c[q]==0||c[q]>z+a[x][q])
			{
				c[q]=z+a[x][q];
				op=1;
				dfs(q,z+a[x][q]);
			}
		}
	}
	if(op==0)
	{
		ans=min(ans,z);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>q1>>q2;
		cin>>a[q1][q2];
		ans+=a[q1][q2];
		b[q1][q2]=1;
		b[q2][q1]=1;
		a[q2][q1]=a[q1][q2];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
