#include<iostream>
using namespace std;
int n,m,k,u,v,w,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		ans=ans+w;
	}
	printf("%d",ans);
	return 0;
}
