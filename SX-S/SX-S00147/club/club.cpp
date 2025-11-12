#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N][4];
int idx[N];
int num[N];
int mmax(int x,int y,int z)
{
	return max(max(x,y),z);
}
void _main()
{
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	int ct1=0,ct2=0,ct3=0;
	for(int i=1;i<=n;i++)
	{
		int mx=mmax(a[i][1],a[i][2],a[i][3]),mxid=0;
		for(int j=1;j<=3;j++) if(a[i][j]==mx) mxid=j;
		ans+=mx;
		if(mxid==1) ct1++;
		if(mxid==2) ct2++;
		if(mxid==3) ct3++;
		idx[i]=mxid;
	}
	if(mmax(ct1,ct2,ct3)<=n/2) 
	{
		cout<<ans<<endl;
		return;
	}
	int k=mmax(ct1,ct2,ct3)-n/2;
	int tot=0,ctid=0;
	if(mmax(ct1,ct2,ct3)==ct1) ctid=1;
	if(mmax(ct1,ct2,ct3)==ct2) ctid=2;
	if(mmax(ct1,ct2,ct3)==ct3) ctid=3;
	for(int i=1;i<=n;i++)
	{
		if(ctid==idx[i]) 
		{
			num[++tot]=a[i][ctid]-a[i][1]-a[i][2]-a[i][3]+a[i][ctid]+min(min(a[i][1],a[i][2]),a[i][3]);
		}
	}
	sort(num+1,num+tot+1);
	for(int i=1;i<=k;i++)
	{
		ans-=num[i];
	}
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) _main();
	return 0;
}
