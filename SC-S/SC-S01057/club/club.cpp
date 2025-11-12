#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int N=100010;

int n,t;
int w[N][3];
struct Score
{
	int id,a,b,c;
};
vector<Score> sc[3];
int rest[3];
int ans;

bool cmp(Score x,Score y)
{
	if(!t) return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
	else if(t==1) return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
	else return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
}

bool cmp1(Score x,Score y)
{
	if(!t)
	{
		if(sc[1].size()>rest[1]) return x.b-x.c<y.b-y.c;
		else return x.c-x.b<y.c-y.b;
	} 
	else if(t==1)
	{
		if(sc[0].size()>rest[0]) return x.a-x.c<y.a-y.c;
		else return x.c-x.a<y.c-y.a;
	} 
	else
	{
		if(sc[0].size()>rest[0]) return x.a-x.b<y.a-y.b;
		else return x.b-x.a<y.b-y.a;
	}
}

void calc(int a,int b)
{
	for(int i=0;i<sc[b].size();i++)
	{
		if(!b) ans+=sc[b][i].a;
		else if(b==1) ans+=sc[b][i].b;
		else ans+=sc[b][i].c;
	}
	
	sort(sc[a].begin(),sc[a].end(),cmp1);
	
	int cnt=sc[a].size();
	for(int i=0;i<sc[a].size();i++)
	{
		if(cnt<=rest[a])
		{
			if(!a) ans+=sc[a][i].a;
			else if(a==1) ans+=sc[a][i].b;
			else ans+=sc[a][i].c;
		}
		else
		{
			if(!b) ans+=sc[a][i].a;
			else if(b==1) ans+=sc[a][i].b;
			else ans+=sc[a][i].c;
			cnt--;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&w[i][j]);
		
		sc[0].clear();
		sc[1].clear();
		sc[2].clear();
		rest[0]=rest[1]=rest[2]=0;
		
		for(int i=1;i<=n;i++)
		{
			int a=w[i][0],b=w[i][1],c=w[i][2];
			if(a>b)
			{
				if(a>c) sc[0].push_back({i,a,b,c});
				else sc[2].push_back({i,a,b,c});
			}
			else
			{
				if(b>c) sc[1].push_back({i,a,b,c});
				else sc[2].push_back({i,a,b,c});
			}
		}
		
		t=-1;
		for(int i=0;i<3;i++)
			if(sc[i].size()>n/2)
			{
				t=i;
				break;
			}
		
		sort(sc[t].begin(),sc[t].end(),cmp);
		
		ans=0;
		for(int i=0;i<3;i++)
		{
			if(i==t) continue;
			
			rest[i]=n/2-sc[i].size();
			for(int j=0;j<sc[i].size();j++)
			{
				if(!i) ans+=sc[i][j].a;
				else if(i==1) ans+=sc[i][j].b;
				else ans+=sc[i][j].c;
			}
			sc[i].clear();
		}
		
		int cnt=sc[t].size();
		for(int i=0;i<sc[t].size();i++)
		{
			if(cnt==n/2)
			{
				if(!t) ans+=sc[t][i].a;
				else if(t==1) ans+=sc[t][i].b;
				else ans+=sc[t][i].c;
			}
			else
			{
				Score x=sc[t][i];
				if(!t)
				{
					if(x.b>x.c) sc[1].push_back(x);
					else sc[2].push_back(x);
				}
				else if(t==1)
				{
					if(x.a>x.c) sc[0].push_back(x);
					else sc[2].push_back(x);
				}
				else
				{
					if(x.a>x.b) sc[0].push_back(x);
					else sc[1].push_back(x);
				}
				
				cnt--;
			}
		}
		
		if(!t)
		{
			if(sc[1].size()>rest[1]) calc(1,2);
			else calc(2,1);
		}
		else if(t==1)
		{
			if(sc[0].size()>rest[0]) calc(0,2);
			else calc(2,0);
		}
		else
		{
			if(sc[0].size()>rest[0]) calc(0,1);
			else calc(1,0);
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}