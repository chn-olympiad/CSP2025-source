#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans,a[100005][5],c[100005],l[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
		int cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			if((a[i][1]>=a[i][2])&&(a[i][1]>=a[i][3]))
			{
				c[i]=1;
				cnt1++;
				ans+=a[i][1];
			}
			else if((a[i][2]>=a[i][1])&&(a[i][2]>=a[i][3]))
			{
				c[i]=2;
				cnt2++;
				ans+=a[i][2];
			}
			else
			{
				c[i]=3;
				cnt3++;
				ans+=a[i][3];
			}
		}
		if((cnt1<=(n/2))&&(cnt2<=(n/2))&&(cnt3<=(n/2)))
		{
			cout<<ans<<"\n";
			continue;
		}
		int d=max(max(cnt1,cnt2),cnt3);
		int p=0;
		if(cnt1==d) 
		{
			p=1;
		}
		else if(cnt2==d) 
		{
			p=2;
		}
		else
		{
			p=3;
		}
		int sum=0;
		for(int i=1;i<=n;++i)
		    if(c[i]==p)
		    {
		    	if(p==1) l[++sum]=a[i][p]-max(a[i][2],a[i][3]);
		    	else if(p==2) l[++sum]=a[i][p]-max(a[i][1],a[i][3]);
		    	else l[++sum]=a[i][p]-max(a[i][1],a[i][2]);
			}
		sort(l+1,l+sum+1);
		for(int i=1;i<=d-(n/2);++i)
		    ans-=l[i];
		cout<<ans<<"\n";   
	}
	return 0;
}
