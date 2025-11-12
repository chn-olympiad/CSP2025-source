#include<bits/stdc++.h>
using namespace std;
const int nn=1e5+20;
int a[3][nn],x,y,z,ma=INT_MIN,n;
void dfs(int w,int b,int k)//b ren k bumen
{
	if(b>n)
	{
		ma=max(ma,w);
		return;
	}
	//cout<<w<<' '<<b<<' '<<k<<"\n";
	w+=a[k][b];
	
	if(k==0) ++x;
	if(k==1) ++y;
	if(k==2) ++z;
	if(x<n/2) dfs(w,b+1,0);
	if(y<n/2) dfs(w,b+1,1);
	if(z<n/2) dfs(w,b+1,2);
	if(k==0) --x;
	if(k==1) --y;
	if(k==2) --z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		for(int j=1;j<=n;++j)
		{
			cin>>a[0][j]>>a[1][j]>>a[2][j];
		}
		x=0;
		y=0;
		z=0;
		ma=INT_MIN;
		dfs(0,1,0);
		dfs(0,1,1);
		dfs(0,1,2);
		cout<<ma<<"\n";
	}
	return 0;
}