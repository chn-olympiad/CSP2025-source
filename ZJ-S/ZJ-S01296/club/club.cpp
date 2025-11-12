#include<bits/stdc++.h>
using namespace std;

struct sati
{
	int a;
	int dep;
};

struct student
{
	sati manyi[4];
	int maxa,max_dep;
	int secenda,secend_dep;
}s[100005];

bool cmp(sati x,sati y)
{
	return x.a>y.a;
}

bool cmp2(student x,student y)
{
	return x.maxa-x.secenda>y.maxa-y.secenda;
}

int t,n,ans;
int pop[5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		pop[1]=0;
		pop[2]=0;
		pop[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&s[i].manyi[1].a,&s[i].manyi[2].a,&s[i].manyi[3].a);
			s[i].manyi[1].dep=1;
			s[i].manyi[2].dep=2;
			s[i].manyi[3].dep=3;
			sort(s[i].manyi+1,s[i].manyi+1+3,cmp);
			
			s[i].maxa=s[i].manyi[1].a;
			s[i].max_dep=s[i].manyi[1].dep;
			s[i].secenda=s[i].manyi[2].a;
			s[i].secend_dep=s[i].manyi[2].dep;
		}
		sort(s+1,s+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(pop[s[i].max_dep]==n/2)//ย๚มห 
			{
				pop[s[i].secend_dep]++;
				ans+=s[i].secenda;
			}
			else
			{
				pop[s[i].max_dep]++;
				ans+=s[i].maxa;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
