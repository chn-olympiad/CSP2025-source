#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3,maxn,max2;
}p[100020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int k=n/2;
		int ans=0;
		int k1=0,k2=0,k3=0;
		int cha1[100020],cha2[100020],cha3[100020],cnt1=1,cnt2=1,cnt3=1;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a1>>p[i].a2>>p[i].a3;
			if(p[i].a1>=p[i].a2&&p[i].a1>=p[i].a3)
			{
				p[i].max2=max(p[i].a2,p[i].a3);
				ans+=p[i].a1;
				p[i].maxn=p[i].a1;
				k1++;
				cha1[cnt1++]=p[i].maxn-p[i].max2;
			}
			else if(p[i].a2>=p[i].a1&&p[i].a2>=p[i].a3)
			{
				p[i].max2=max(p[i].a1,p[i].a3);
				ans+=p[i].a2;
				p[i].maxn=p[i].a2;
				k2++;
				cha2[cnt2++]=p[i].maxn-p[i].max2;
			}
			else
			{
				p[i].max2=max(p[i].a2,p[i].a1);
				ans+=p[i].a3;
				p[i].maxn=p[i].a3;
				k3++;
				cha3[cnt3++]=p[i].maxn-p[i].max2;
			}
		}
		sort(cha1+1,cha1+cnt1);	
		sort(cha2+1,cha2+cnt2);	
		sort(cha3+1,cha3+cnt3);	
		if(k1>=k)
		{
			for(int i=1;i<=k1-k;i++)
				ans-=cha1[i];
		}
		else if(k2>=k)
		{
			for(int i=1;i<=k2-k;i++)
				ans-=cha2[i];
		}
		else if(k3>=k)
		{
			for(int i=1;i<=k3-k;i++)
				ans-=cha3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}