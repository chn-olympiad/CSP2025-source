#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
int a[100005][3];
int flag[300005];
int fl[100005];
int cha21[300005];
int cha32[300005];
int cha31[300005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int flag2=0,flag3=0;
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cha21[i]=a[i][2]-a[i][1];
			cha32[i]=a[i][3]-a[i][2];
			cha31[i]=a[i][3]-a[i][1];
			if(a[i][2]!=0)flag2=1;
			if(a[i][3]!=0)flag3=1;
			ans+=a[i][1];
		}
		
		
		if(flag2==0&&flag3==0)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				flag[i]=a[i][1];
				ans+=a[i][1];
			}
			sort(flag+1,flag+1+n);
			for(int i=1;i<=n/2;i++)
			{
				ans-=flag[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		
		if(flag3==0)
		{
			int fl1=0,fl2=0;
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i][1];
			}
			sort(cha21+1,cha21+1+n);
			for(int i=n;i>=n/2;i--)
			{
				ans+=cha21[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		
		
		


		int cnt1=n,cnt2=0,cnt3=0;
		for(int i=n;i>=n/2;i--)
		{
			if(cnt2==n/2)break;
			if(cha21[i]>0)
			{
				fl[i]=1;
				ans+=cha21[i];
				cnt1--;
				cnt2++;
			}
		}
		
		
		for(int i=n;i>=1;i--)
		{
			if(cnt3==n/2)break;
			if(cha31[i]>0)
			{
				fl[i]=1;
				ans+=cha31[i];
				cnt1--;
				cnt3++;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(cnt3==n/2)break;
			if(cha32[i]>0)
			{
				fl[i]=1;
				ans+=cha32[i];
				cnt2--;
				cnt3++;
			}
		}
		if(cnt1>n/2)
		{
			for(int i=n;i>=1;i++)
			{
				if(cnt1==n/2)break;
				if(fl[i]==0)
				{
					ans+=max(cha21[i],cha31[i]);
					cnt1--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

