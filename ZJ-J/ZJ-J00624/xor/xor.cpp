#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pir;
pir sum[500005];
struct stu
{
	long long l,r;
};
vector<stu> v;
long long a[500005];
long long s[500005];
long long n,k;
long long found(long long t)
{
	long long l=1,r=n;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(sum[mid].first>=t) r=mid;
		else l=mid+1;
	}
	return l;
}
bool cmp(stu a,stu b)
{
	if(a.r!=b.r) return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		sum[i]={s[i],i};
	}
	long long cnt=0;
	if(n<=1000)
	{
		for(long long i=1;i<=n;i++)
	 	  for(long long j=i;j<=n;j++)
	   	    if((s[j]^s[i-1])==k) v.push_back({i,j});
	}
	else 
	{
		sort(sum+1,sum+1+n);
		for(long long i=1;i<=n;i++)
		{
			long long pos=found(k^s[i-1]);
			if(sum[pos].first!=(k^s[i-1])) continue;
			while(pos<=n&&sum[pos].first==(k^s[i-1]))
			{
				if(sum[pos].second>=i) v.push_back({i,sum[pos].second});
				pos++;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	long long p=-1,ans=0;
	for(long long i=0;i<v.size();i++)
	{
		if(v[i].l>p)
		{
			ans++;
			p=v[i].r;
		}
	}
	cout<<ans;
	return 0;
}
