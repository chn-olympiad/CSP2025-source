#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],x,ans,MAX,b[500010],sum,pMAX,plMAX;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),MAX=max(MAX,a[i]);
	if(k<=1&&MAX<=1)
	{
		for(int i=1;i<=n;i++)
		{
			x=(x^a[i]);
			if(x==k||a[i]==k) ans++,x=0;
		}
	}
	else
	{
		if(a[1]!=k) b[++sum]=0;
		for(int i=1;i<=n;i++)
		if(a[i]==k) b[++sum]=i,ans++;
		b[++sum]=n+1;
		for(int i=1;i<=sum-1;i++)
		{
			plMAX=0;
			for(int j=b[i]+1;j<b[i+1];j++)
			{
				x=0;pMAX=0;
				for(int l=j;l<b[i+1];l++)
				{
					x=(x^a[l]);
					if(x==k) pMAX++,x=0;
				}
				plMAX=max(plMAX,pMAX);
			}
			ans+=plMAX;
		}
	}
	cout<<ans<<endl;
	return 0;
}
