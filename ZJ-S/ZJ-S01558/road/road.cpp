#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int b[15][10005];
struct node
{
	int u,v,w;
}a[10005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	std::cin.tie(NULL);
 	std::cout.tie(NULL);
 	cin>>n>>m>>k;
 	for(int i=1;i<=m;i++)
 	{
 		cin>>a[i].u>>a[i].v>>a[i].w;
	 }
	 for(int i=1;i<=k;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		cin>>b[i][j];
		 }
	 }
	 sort(a+1,a+1+n,cmp);
	 long long ans=0;
	 for(int i=1;i<=n;i++)
	 {
	 	ans+=a[i].w;
	 }
	 cout<<ans<<endl;
 	return 0;
}
