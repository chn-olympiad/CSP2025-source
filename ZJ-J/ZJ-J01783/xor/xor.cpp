#include<bits/stdc++.h>
using namespace std;
struct data
{
	int s,f;
	bool is;
}b[500001];
int n,k,a[500001];
bool cmp(data x,data y)
{
	return x.f<y.f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		long long t=a[i],j=i;
		while(t!=k&&j<n)
		{
			j++;
			t^=a[j];
		}
		if(t!=k)b[i].is=1;
		b[i].f=j;
		b[i].s=i;
	}
	sort(b+1,b+1+n,cmp);
	int t=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i].s>t&&!b[i].is)ans++,t=b[i].f;
	}
	cout<<ans;
	return 0;
}