#include<bits/stdc++.h>
using namespace std;
int t;
int st[100005],nd[100005];
int s1[100005],s2[100005],s3[100005];
int mi[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		memset(st,0,sizeof(st));
		memset(nd,0,sizeof(nd));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(mi,0,sizeof(mi));
		int m1,m2,m3,ans=0;m1=m2=m3=0;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b)
			{
				if(a>=c)
				{
					if(b>=c)st[i]=a,nd[i]=b,s1[++m1]=i;
					else st[i]=a,nd[i]=c,s1[++m1]=i;
				}
				else st[i]=c,nd[i]=a,s3[++m3]=i;
			}
			else
			{
				if(b>=c)
				{
					if(a>=c)st[i]=b,nd[i]=a,s2[++m2]=i;
					else st[i]=b,nd[i]=c,s2[++m2]=i;
				}
				else st[i]=c,nd[i]=b,s3[++m3]=i;
			}
		}
		for(int i=1;i<=n;i++)ans+=st[i];
		if(m1>n/2)	
		{
			for(int i=1;i<=m1;i++)
				mi[i]=st[s1[i]]-nd[s1[i]];
			sort(mi+1,mi+1+m1);
			for(int i=1;i<=m1-n/2;i++)ans-=mi[i];
		}
		if(m2>n/2)	
		{
			for(int i=1;i<=m2;i++)
				mi[i]=st[s2[i]]-nd[s2[i]];
			sort(mi+1,mi+1+m2);
			for(int i=1;i<=m2-n/2;i++)ans-=mi[i];
		}
		if(m3>n/2)	
		{
			for(int i=1;i<=m3;i++)
				mi[i]=st[s3[i]]-nd[s3[i]];
			sort(mi+1,mi+1+m3);
			for(int i=1;i<=m3-n/2;i++)ans-=mi[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
