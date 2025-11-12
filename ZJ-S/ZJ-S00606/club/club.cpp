#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100005][4],t,cz1[100005],cz2[100005],cz3[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int mx=n/2,ans=0,q,cnt1=1,cnt2=1,cnt3=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				cz1[cnt1]=a[i][1]-max(a[i][2],a[i][3]);
				cnt1++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				cz2[cnt2]=a[i][2]-max(a[i][1],a[i][3]);
				cnt2++;
			}
			else
			{
				cz3[cnt3]=a[i][3]-max(a[i][1],a[i][2]);
				cnt3++;
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cnt1--;cnt2--;cnt3--;
		sort(cz1+1,cz1+1+cnt1);
		sort(cz2+1,cz2+1+cnt2);
		sort(cz3+1,cz3+1+cnt3);
		int k=1;
		while(cnt1>mx)
		{
			ans-=cz1[k];
			cnt1--;
			k++;
		}
		while(cnt2>mx)
		{
			ans-=cz2[k];
			cnt2--;
			k++;
		}
		while(cnt3>mx)
		{
			ans-=cz3[k];
			cnt3--;
			k++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
