#include<bits/stdc++.h>
using namespace std;
struct myd{
	int maxn,midn,bh;
	int a,b,c;
}s[100005];
int num[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>s[i].b&&s[i].a>s[i].c)
			{
				s[i].maxn=s[i].a,s[i].midn=max(s[i].b,s[i].c); 
				s[i].bh=1;
			}
			else if(s[i].b>s[i].a&&s[i].b>s[i].c)
			{
				s[i].maxn=s[i].b,s[i].midn=max(s[i].a,s[i].c);
				s[i].bh=2;
			}
			else 
			{
				s[i].maxn=s[i].c,s[i].midn=max(s[i].a,s[i].b);
				s[i].bh=3;
			}
		}
		int sum=0,cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j].bh==1&&num[1]<n/2)
				sum+=s[j].maxn,num[1]++;
			else if(s[j].bh==2&&num[2]<n/2)
				sum+=s[j].maxn,num[2]++;
			else if(s[j].bh==3&&num[3]<n/2)
				sum+=s[j].maxn,num[3]++;
			else
			{
				int sum2=0;
				sum2=s[1+cnt].midn;
				for(int k=2+cnt;k<=j;k++)
					sum2+=s[k].maxn;
				for(int k=1;k<cnt;k++)
					sum2+=s[k].maxn;
				sum=max(sum+s[j].midn,sum2);
				cnt++;
			}
		}
		cout<<sum<<endl;
		num[1]=0,num[2]=0,num[3]=0;
	}
	return 0;
}
