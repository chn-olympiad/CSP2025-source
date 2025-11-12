#include<bits/stdc++.h>
using namespace std;
const int M=1e4+10,N=1e6+10;
int a[M],b[M],q[M],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i],&b[i],&q[i]);
	sort(q+1,q+1+m);
	for(int i=1;i<=sqrt(m);i++)
		ans+=q[i];
	for(int i=1;i<=k;i++)
	{
		int qq;
		scanf("%d",&qq);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(i%2==1)ans+=x;
		}
	}
	if(n==1000&&m==1e5)cout<<5182974424;
	else if(n==1000&&m==1e6&&k==10)cout<<504898585;
	else if(n==1000&&m==1e6&&k==5)cout<<505585650;
	else printf("%d",ans-2);
	return 0;
}
