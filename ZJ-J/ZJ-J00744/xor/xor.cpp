#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,NN=5e5+5;
int n,k,cnt,ans,a[NN],b[NN];
pair<int,int>p[N*N];
bool cmp(pair<int,int>x,pair<int,int>y)
{
	return x.second<y.second;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=b[i-1]^a[i];
	if(k<=1)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
					ans++;
				else if(i<n&&a[i]==a[i+1])
					ans++,i++;
			}
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((b[j]^b[i-1])==k)
				p[++cnt]=make_pair(i,j);
	sort(p+1,p+1+cnt,cmp);
	pair<int,int>last;
	for(int i=1;i<=cnt;i++)
		if(p[i].first>last.second)
			ans++,last=p[i];
	cout<<ans;
}