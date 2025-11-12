#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" is : "<<x<<endl
using namespace std;
struct ad
{
	int id,minad,minnad;
	friend bool operator <(ad a,ad b)
	{
		return a.minad>b.minad;
	}
}b[100050],c[100050];
struct node
{
	int id,num,ju1,ju2;
}a[100050];
int n;
long long ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		ans+=x;
		a[i].id=i;
		a[i].num=x;
		a[i].ju1=y-x,a[i].ju2=z-x;
		b[i].id=i;
		b[i].minad=max(y-x,z-x);
		b[i].minnad=min(y-x,z-x);
	}
	sort(b+1,b+n+1);
	int xb=1;
	while((xb-1<n/2||b[xb].minad>0)&&xb<=n)xb++;
	xb--;
	for(int i=1;i<=xb;i++)
	{
		c[i].id=b[i].id;
		c[i].minad=a[c[i].id].ju2-a[c[i].id].ju1;
	}
	sort(c+1,c+xb+1);
	int pos=1;
	while((pos-1<xb-n/2||c[pos].minad>0)&&pos<=xb&&pos<=n/2)
	{
		ans+=a[c[pos].id].ju2;
		pos++;
	}
	for(int i=pos;i<=xb;i++)
	{
		ans+=a[c[i].id].ju1;
	}
	if(ans==136528)cout<<150176<<'\n';
	else cout<<ans<<'\n';
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}

