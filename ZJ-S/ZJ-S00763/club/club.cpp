#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,ans,k,f[5],a[N],b[N],c[N];
signed main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		f[1]=f[2]=f[3]=0;
		priority_queue<int,vector<int>,greater<int> >x,y,z;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				f[1]++;
				ans+=a[i];
				x.push(min(a[i]-b[i],a[i]-c[i]));
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				f[2]++;
				ans+=b[i];
				y.push(min(b[i]-a[i],b[i]-c[i]));
			}
			else
			{
				f[3]++;
				ans+=c[i];
				z.push(min(c[i]-a[i],c[i]-b[i]));
			}
		}
		k=1;
		if(f[1]>n/2)
		{
			while(f[1]>n/2)
			{
				ans-=x.top();
				x.pop();
				f[1]--;
			}
		}
		else if(f[2]>n/2)
		{
			while(f[2]>n/2)
			{
				ans-=y.top();
				y.pop();
				f[2]--;
			}
		}
		else if(f[3]>n/2)
		{
			while(f[3]>n/2)
			{
				ans-=z.top();
				z.pop();
				f[3]--;
			}
		}
		cout<<ans<<"\n";
	}
 	return 0;
}
