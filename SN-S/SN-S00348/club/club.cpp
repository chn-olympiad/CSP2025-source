// T1打了半个小时感觉自己没救了
//xt66666
//lizihanDF好帅！ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll t;
ll n;
struct node
{
	ll a,b,c;
}a[100010];
bool cmp(node x,node y)
{
	ll a[5]={0,x.a,x.b,x.c},b[5]={0,y.a,y.b,y.c};
	sort(a+1,a+3+1);
	sort(b+1,b+3+1);
	return (a[3]-a[2])>(b[3]-b[2]);
}

bool v[100010]={0};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		ll aa,b,c;
		aa=b=c=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll d=0;
			if(aa<n/2)
			{
				d=max(d,a[i].a);
			}
			if(b<n/2)
			{
				d=max(a[i].b,d);
			}
			if(c<n/2)
			{
				d=max(d,a[i].c);
			}
			ans+=d;
			if(a[i].a==d&&aa<n/2)
			{
				aa++;
			}
			else if(a[i].b==d&&b<n/2)
			{
				b++;
			}
			else
			{
				c++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
