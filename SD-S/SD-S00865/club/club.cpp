#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int id1[5];
int cnt=0;
long long ans=0;
struct node
{
	int id2;
	int sc;
	int id3;
}s[100010];
struct stu
{
	int s[5];
	int p[5];
}a[100010];
/*
bool cmp1(stu x,stu y)
{
	return x.s[1]>y.s[1];
}
bool cmp2(stu x,stu y)
{
	return x.s[2]>y.s[2];
}
bool cmp3(stu x,stu y)
{
	return x.s[3]>y.s[3];
}
bool pd()
{
	if(id1[1]<=(n>>1)&&id1[2]<=(n>>1)&&id1[3]<=(n>>1))
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
			ans+=s[i].sc;
		cout<<ans<<'\n';
		return 0;
	}
	return 1;
}
*/
bool cmp(node x,node y)
{
	return x.sc>y.sc;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		ans=0;
		memset(id1,0,sizeof id1);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			if(a[i].s[1]>=a[i].s[2]&&a[i].s[2]>=a[i].s[3])
				a[i].p[1]=1,a[i].p[2]=2,a[i].p[3]=3;
			else if(a[i].s[1]>=a[i].s[3]&&a[i].s[2]<=a[i].s[3])
				a[i].p[1]=1,a[i].p[2]=3,a[i].p[3]=2;
			else if(a[i].s[1]<=a[i].s[2]&&a[i].s[1]>=a[i].s[3])
				a[i].p[1]=2,a[i].p[2]=1,a[i].p[3]=3;
			else if(a[i].s[1]<=a[i].s[3]&&a[i].s[2]>=a[i].s[3])
				a[i].p[1]=2,a[i].p[2]=3,a[i].p[3]=1;
			else if(a[i].s[3]>=a[i].s[1]&&a[i].s[2]<=a[i].s[1])
				a[i].p[1]=3,a[i].p[2]=1,a[i].p[3]=2;
			else if(a[i].s[1]<=a[i].s[2]&&a[i].s[2]<=a[i].s[3])
				a[i].p[1]=3,a[i].p[2]=2,a[i].p[3]=1;
		}
		
		for(int i=1;i<=n;i++)
		{
			s[i].id3=a[i].p[1];
			s[i].sc=a[i].s[a[i].p[1]];
			s[i].id2=i;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(++id1[s[i].id3]<=(n>>1))
				ans+=s[i].sc;
			else
			{
				s[i].id3++;
				s[i].sc=a[i].s[a[i].p[s[i].id3]];
				sort(s+1+i,s+1+n,cmp);
			}
		}
		
		cout<<ans<<'\n';
		/*
		bool flag=pd();
		int i=n;
		while(flag)
		{
			for(int k=1;k<=3;k++)
			{
				if(id1[k]>(n>>1)&&a[s[i].id2].p[s[i].id3]==k)
				{
					id1[k]--;
					s[i].id3=a[s[i].id2].p[s[i].id3+1>3?1:s[i].id3+1];
					s[i].sc=a[s[i].id2].s[a[i].p[s[i].id3]];
					id1[s[i].id3]++;
					i--;
					if(i==0)
						i=n;
				}
			}
			i--;
			if(i==0)
				i=n;
			flag=pd();
		}
		*/
		
	}
	
	return 0;
}

