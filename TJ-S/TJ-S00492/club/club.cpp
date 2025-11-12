#include<bits/stdc++.h>
using namespace std;
long long T,n,a1,a2,a3,ans,cnt;
struct nod
{
	int id,ch;
}b[100005];
bool cmp(nod x,nod y)
{
	if(x.ch!=y.ch)
	{
		return x.ch<y.ch;
	}
	return x.id<y.id;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ma[100005],ma2[100005],t[100005],t2[100005],h[100005];
		cnt=0;
		ans=0;
		memset(ma,0,sizeof(ma));
		memset(ma2,0,sizeof(ma2));
		memset(t,0,sizeof(t));
		memset(t2,0,sizeof(t2));
		memset(h,0,sizeof(h));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1>=a2&&a1>=a3)
			{
				ma[i]=a1;
				t[i]=1;
				if(a2>=a3)
				{
					ma2[i]=a2;
					t2[i]=2;
				}
				else
				{
					ma2[i]=a3;
					t2[i]=3;
				}
			}
			else if(a2>=a1&&a2>=a3)
			{
				ma[i]=a2;
				t[i]=2;
				if(a1>=a3)
				{
					ma2[i]=a1;
					t2[i]=1;
				}
				else
				{
					ma2[i]=a3;
					t2[i]=3;
				}
			}
			else if(a3>=a1&&a3>=a2)
			{
				ma[i]=a3;
				t[i]=3;
				if(a1>=a2)
				{
					ma2[i]=a1;
					t2[i]=1;
				}
				else
				{
					ma2[i]=a2;
					t2[i]=2;
				}
			}
			b[i].ch=ma[i]-ma2[i];
			b[i].id=i;
			h[t[i]]++;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=3;i++)
		{
			if(h[i]>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					if(t[b[j].id]==i)
					{
						cnt++;
						t[b[j].id]=t2[b[j].id];
						ma[b[j].id]=ma2[b[j].id];
					}
					if(cnt==h[i]-(n/2))
					{
						break;
					}
				}
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=ma[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
