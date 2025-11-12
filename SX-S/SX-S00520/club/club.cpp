#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N],b[N],c[N],maxx[5],ans,cnt[5];
struct Number
{
	int id,k,p;
}d[N];
bool cmp(Number X,Number Y)
{
	return X.k>Y.k;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		//clear
		cin>>n;
		memset(maxx,0,sizeof maxx);
		memset(d,0,sizeof d);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			maxx[1]=max(maxx[1],a[i]);
			maxx[2]=max(maxx[2],b[i]);
			maxx[3]=max(maxx[3],c[i]);
		}
		for(int i=1;i<=n;i++)
		{
			d[i].id=i;
			if(a[i]==max(a[i],max(b[i],c[i])))
				d[i].p=1,d[i].k=a[i]-max(b[i],c[i]);
			if(b[i]==max(a[i],max(b[i],c[i])))
				d[i].p=2,d[i].k=b[i]-max(a[i],c[i]);
			if(c[i]==max(a[i],max(b[i],c[i])))
				d[i].p=3,d[i].k=c[i]-max(b[i],a[i]);
		}
		sort(d+1,d+1+n,cmp);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int id=d[i].id,p=d[i].p;
			if(cnt[p]<n/2)
			{
				cnt[p]++;
				if(p==1) ans+=a[id];
				else if(p==2) ans+=b[id];
				else ans+=c[id];
			}
			else
			{
				if(p==1) ans+=max(b[id],c[id]);
				else if(p==2) ans+=max(a[id],c[id]);
				else ans+=max(a[id],b[id]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//T1-club
//ept:100pts