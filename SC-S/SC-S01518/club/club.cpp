#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010][4];
int x,y,z;
int b[100010];
long long ans;
int k;
int cha;
bool cmp(int a,int b)
{
	return a<b;
}
void solve(int aa,int b,int c,int d)
{
	if(aa>b&&aa>c)
	{
		x++;
		a[d][3]=1;
		ans+=aa;
		return;
	}
	if(b>c)
	{
		y++;
		a[d][3]=2;
		ans+=b;
		return;
	}
	z++;
	a[d][3]=3;
	ans+=c;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		x=0;y=0;z=0;k=0;ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			solve(a[i][0],a[i][1],a[i][2],i);
		}
		if(x>n/2)
		{
			cha=x-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i][3]==1)
				{
					b[k++]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				}
			}
		}
		if(y>n/2)
		{
			cha=y-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i][3]==2)
				{
					b[k++]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				}
			}
		}
		if(z>n/2)
		{
			cha=z-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i][3]==3)
				{
					b[k++]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				}
			}
		}
		sort(b,b+k,cmp);
		for(int i=0;i<cha;i++)
		{
			ans-=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}