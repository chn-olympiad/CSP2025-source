#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010][21],c[30];
struct pp
{
	int l,r;
}ji[500010];
int cmp(pp x,pp y)
{
	if(x.l==y.l)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,m,k,ans=0,h=0,j,p;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		cin>>a[i];
		int x=a[i],t=0;
		while(x!=0)
		{
			c[++t]=x%2;
			x=x/2;
			//cout<<c[t]<<" ";
		}
		//cout<<endl;
		int s=20;
		for(j=1;j<=20;j++)
		{
			if(b[i-1][s]!=c[j])
			{
				b[i][s]=1;
			}
			else
			{
				b[i][s]=0;	
			}
			s--;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=20;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			int y=0;
			for(p=20;p>=1;p--)
			{
				int g;
				if(b[i][p]==b[j][p])
				{
					continue;
				}
				else
				{
					y+=pow(2,20-p);
				}
			}
			if(y==k)
			{
				h++;
				ji[h].l=i+1;
				ji[h].r=j;
				//cout<<i+1<<" "<<j<<endl;
			}
		}
	}
	sort(ji+1,ji+1+h,cmp);
	ji[h+1].l=99999999;
	int ll1=0;
	for(i=1;i<=h;i++)
	{
		if(ji[i].l>ll1&&ji[i].r<ji[i+1].l)
		{
			ans++;
			ll1=ji[i].r;
		}
		else if(ji[i].l>ll1)
		{
			ll1=min(ji[i].r,ji[i+1].r);
			//cout<<i<<" "<<j<<endl;
			ans++;
			i++;
		}
	}
	cout<<ans;
	return 0;
}