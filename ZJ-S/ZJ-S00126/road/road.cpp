#include<bits/stdc++.h>
using namespace std;
struct G
{
	int a,b,c;
	bool operator<(const G g)
	{
		return c<g.c;
	}
}g[100001];
long long prim(G g[],int n,int m)
{
	sort(g+1,g+m+1);
	bool flag[n+1]={0};
	int ans=0;
	for(int i=0,j=1;j<n;)
	{
		i++;
		if(flag[g[i].a]&&flag[g[i].b])continue;
		flag[g[i].a]=1;
		flag[g[i].b]=1;
		j++;
		ans+=g[i].c;
	}
	return ans;
}
long long n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	cin>>g[i].a>>g[i].b>>g[i].c;
	}
    cout<<prim(g,n,m);
    return 0;
}
