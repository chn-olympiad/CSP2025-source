#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,sum;
int a[500005];
int ans;
bool mark[500005];
void visit(int x,int y)
{
	//cout<<x<<' '<<y<<endl;
	for(int i=x;i<=y;i++)
	    mark[i]=true;
	ans++;
}
bool flag;
signed main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) flag=false;
	}
	if(k==1 && flag) 
	{
		printf("%lld",n);
		return 0;
	}
	if(k==0 && flag)
	{
		printf("%lld",n/2);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(mark[i]) continue;
		sum=a[i];
		if(sum==k) 
		{
			//cout<<9;
			visit(i,i);
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(mark[j]) break;
			sum^=a[j];
			if(sum==k) 
			{
				visit(i,j);
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;//完结撒花
}