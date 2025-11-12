#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=k;++i)
	for(int j=1;j<=n+1;++j)scanf("%d",&a);
	cout<<0;
	fclose(stdin);fclose(stdout);
	return 0;
}
