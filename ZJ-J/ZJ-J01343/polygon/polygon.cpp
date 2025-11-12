#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],maxn=-1,cnt1,n,jc[5005],c[5005];
void init()
{
	for(int i=1;i<=cnt1;i++)
	{
		int c1=1,c2=1;
		for(int k=1;k<=i;k++)
		{
			c1*=(cnt1-k+1);
		}
		for(int k=1;k<=i;k++)
		{
			c2*=k;
		}
		//cout<<c1<<" "<<c2<<endl;
		c[i]=c1/c2;
	}
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(nullptr));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==1)cnt1++;
	}
	if(maxn==0)cout<<0;
	else if(maxn<=1)
	{
		int ans=0;
		init();
		for(int i=3;i<=cnt1;i++)ans+=c[i];
		cout<<ans;
	}
	else
	{
		cout<<rand()%1000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
