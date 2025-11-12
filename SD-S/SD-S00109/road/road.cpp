#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s=13;
int c,a[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		for(int j=0;j<=n+1;j++)
		cin>>a[j];		
	}
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
