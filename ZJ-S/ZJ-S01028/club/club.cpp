//bqq miaomiaomiao
//100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int a,b,c;
	int mx,d,id;
}a[100010];
struct bqq
{
	int x,id;
}b[5];
bool cmp(node x,node y)
{
	return x.d>y.d;
}
bool cmpb(bqq x,bqq y)
{
	return x.x>y.x;
}
int v[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(v,0,sizeof(v));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			b[1].x=a[i].a,b[1].id=1,b[2].x=a[i].b,b[2].id=2,b[3].x=a[i].c,b[3].id=3;
			sort(b+1,b+4,cmpb),a[i].mx=b[1].x,a[i].d=b[1].x-b[2].x,a[i].id=b[1].id;
		}
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		int cnt[5]={0,0,0,0};
		int i;
		int ez=0;
		for(i=1;i<=n;i++)
		{
			ans+=a[i].mx,v[i]=a[i].id,cnt[a[i].id]++;
			if(cnt[1]>=n/2)
			{
				ez=1;
				break;
			}
			if(cnt[2]>=n/2)
			{
				ez=2;
				break;
			}
			if(cnt[3]>=n/2)
			{
				ez=3;
				break;
			}
		}
		for(;i<=n;i++)
		{
			if(!v[i])
			{
				int x;
				if(ez==1)
				{
					x=max(a[i].b,a[i].c);
				}
				else if(ez==2)
				{
					x=max(a[i].a,a[i].c);
				}
				else
				{
					x=max(a[i].a,a[i].b);
				}
				ans+=x;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}