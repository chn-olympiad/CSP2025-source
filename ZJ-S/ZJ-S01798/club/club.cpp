#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,t,a[N],b[N],c[N],d[N];
bool cmp(pair<int,int> _1,pair<int,int> _2)
{
	return _1.first<_2.first;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		vector<pair<int,int>> ra,rb,rc;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			int mx=max(a[i],max(b[i],c[i]));
			int mi=min(a[i],min(b[i],c[i]));
			d[i]=a[i]+b[i]+c[i]-mx-mi;
			d[i]=mx-d[i];
			if(a[i]==mx) ra.push_back({d[i],i});
			if(b[i]==mx) rb.push_back({d[i],i});
			if(c[i]==mx) rc.push_back({d[i],i});
			sum+=mx;
		}
		if(ra.size()>n/2)
		{
			sort(ra.begin(),ra.end(),cmp);
			int sz=ra.size()-(n/2);
			for(int i=0;i<sz;i++) sum-=ra[i].first;
		}
		if(rb.size()>n/2)
		{
			sort(rb.begin(),rb.end(),cmp);
			int sz=rb.size()-(n/2);
			for(int i=0;i<sz;i++) sum-=rb[i].first;
		}
		if(rc.size()>n/2)
		{
			sort(rc.begin(),rc.end(),cmp);
			int sz=rc.size()-(n/2);
			for(int i=0;i<sz;i++) sum-=rc[i].first;
		}
		cout<<sum<<"\n";
	}
}

