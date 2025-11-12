#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a1[N],a2[N],a3[N],hao[N];
int num1=0,num2=0,num3=0;
ll ans=0;
priority_queue<int>q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		num1=0,num2=0,num3=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a1[i]>=a2[i]&&a1[i]>=a3[i])
			{
				hao[i]=1;
				ans+=a1[i];
				num1++;
			}
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
			{
				hao[i]=2;
				ans+=a2[i];
				num2++;			
			}
			else if(a3[i]>=a1[i]&&a3[i]>=a2[i])
			{
				hao[i]=3;
				ans+=a3[i];
				num3++;		
			}
		}
		if(num1<=n/2&&num2<=n/2&&num3<=n/2)
		{
			printf("%lld\n",ans);
			continue;
		}
		while(!q.empty()) q.pop();
		if(num1>n/2)
		{
			int shu=num1-n/2;
			for(int i=1;i<=n;i++)
			{
				if(hao[i]==1)
				{
					q.push(max(a2[i]-a1[i],a3[i]-a1[i]));
				}
			}
			for(int i=1;i<=shu;i++)
			{
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);
		}
		else if(num2>n/2)
		{
			int shu=num2-n/2;
			for(int i=1;i<=n;i++)
			{
				if(hao[i]==2)
				{
					q.push(max(a1[i]-a2[i],a3[i]-a2[i]));
				}
			}
			for(int i=1;i<=shu;i++)
			{
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);			
		}
		else if(num3>n/2)
		{
			int shu=num3-n/2;
			for(int i=1;i<=n;i++)
			{
				if(hao[i]==3)
				{
					q.push(max(a1[i]-a3[i],a2[i]-a3[i]));
				}
			}
			for(int i=1;i<=shu;i++)
			{
				ans+=q.top();
				q.pop();
			}
			printf("%lld\n",ans);			
		}
	}
	return 0;
} 
