#include <bits/stdc++.h>
//#include <random>
#include <ctime>

using namespace std;

const int MAXN=1e5+10;

struct Point
{
	int a[4],d;
	
	bool operator< (const Point& other) const
	{
		return d<other.d;
	}
};

int T;
int N;

Point p[MAXN];

int ch[4];

double Rate()
{
	return 1.0*rand()/(1.0*RAND_MAX);
}

long long SA()
{
	double Ts=5000,Te=1e-15,d=0.998;
	
	long long cur=0,nxt,best=0;
	
	for(int i=1;i<=N;i++)
	{
		cur+=p[i].a[p[i].d];
	}
	
	best=cur;
	
	while(Ts>Te)
	{
		int x=rand()%N+1,y=1;
		while(y==p[x].d||ch[y]>=N/2)
		{
			y=rand()%3+1;
		}
		
		nxt=cur-p[x].a[p[x].d]+p[x].a[y];
		
		if(nxt<cur)
		{
			cur=nxt;
			ch[p[x].d]--;
			ch[y]++;
			p[x].d=y;
			
		}
		else if(exp(1.0*(cur-nxt)/Ts)>Rate())
		{
			cur=nxt;
			ch[p[x].d]--;
			ch[y]++;
			p[x].d=y;
		}
		
		best=max(best,cur);
		Ts*=d;
	}
	
	return best;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	srand(time(0));
	
	cin>>T;
	//int tim=clock();
	while(T--)
	{
		long long ans=0;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
		}
		
		memset(ch,0,sizeof ch);
		
		for(int i=1;i<=N/2;i++)
		{
			p[i].d=1;
		}
		
		for(int i=N/2+1;i<=N/2+N/4;i++)
		{
			p[i].d=2;
		}
		
		for(int i=N/2+N/4+1;i<=N;i++)
		{
			p[i].d=3;
		}
		
		for(int i=1;i<=N;i++)
		{
			ch[p[i].d]++;
		}
		
		for(int i=1;i<=70;i++)
		{
			ans=max(ans,SA());
		}
		
		cout<<ans<<'\n';
	}
	
	//cout<<clock()-tim<<'\n';
	
	return 0;
} 