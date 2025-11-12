#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int r[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b>a)swap(a,b);
		if(r[a][b]==0)ans+=c,r[a][b]=c;
		else if(r[a][b]>c)ans=ans-r[a][b]+c;
	}
	printf("%d",ans);
	return 0;
}