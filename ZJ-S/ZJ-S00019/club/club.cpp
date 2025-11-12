#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node
{
	int val,pos;
}a[100100],b[100100],c[100100];
int dp1[100100],dp2[100100],dp3[100100];
bool cmp(node x,node y)
{
	return x.val>y.val;
}
map<int,int> mp;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		a[0].val=-1;
		b[0].val=-1;
		c[0].val=-1;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			mp[i]=0;
		}
		int cnt1=1,cnt2=1,cnt3=1,cnt11=1,cnt22=1,cnt33=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].val>>b[i].val>>c[i].val;
			a[i].pos=i;
			b[i].pos=i;
			c[i].pos=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			while(mp[a[cnt1].pos])
			{
				cnt1++;
			}
			while(mp[b[cnt2].pos])
			{
				cnt2++;
			}
			while(mp[c[cnt3].pos])
			{
				cnt3++;
			}
			if(cnt11>n/2)
			{
				cnt1=0;
			}
			if(cnt22>n/2)
			{
				cnt2=0;
			}
			if(cnt33>n/2)
			{
				cnt3=0;
			}
			int Mx=max(a[cnt1].val,max(b[cnt2].val,c[cnt3].val));
			if(a[cnt1].val==Mx)
			{
				mp[a[cnt1].pos]=1;
				ans+=a[cnt1].val;
				cnt1++;
				cnt11++;
			}
			else if(b[cnt2].val==Mx)
			{
				mp[b[cnt2].pos]=1;
				ans+=b[cnt2].val;
				cnt2++;
				cnt22++;
			}
			else
			{
				mp[c[cnt3].pos]=1;
				ans+=c[cnt3].val;
				cnt3++;
				cnt33++;
			}
		}
		cout<<ans<<endl;
	}
}