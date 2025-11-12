#include <bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') ch=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
#define fi first 
#define se second 
#define mp make_pair
#define ll long long
struct ren
{
	pair<int,int> a[4];
	int nowei;//123
	ll cha;
	
}p[100006];
bool operator < (ren q,ren w)
{
	return q.cha>w.cha;
}
priority_queue<ren> q1;
priority_queue<ren> q2;
priority_queue<ren> q3;
int num[4];
signed main()
{

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();

	while(T--)
	{
		int n=read(); 
			while(!q1.empty()) q1.pop();
			while(!q2.empty()) q2.pop();
			while(!q3.empty()) q3.pop();

for(int i=1;i<=3;i++)
{
	num[i]=0;
}
		memset(p,0,sizeof p);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				int x=read();
				p[i].a[j]=mp((-1)*x,j);
			}
			sort(p[i].a+1,p[i].a+4);
		}
		
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int want=p[i].a[1].se;
			p[i].nowei=1;
			num[want]++;
			
			p[i].cha=(-1)*p[i].a[1].fi-(-1)*p[i].a[2].fi;
			if(want==1) q1.push(p[i]);
			if(want==2) q2.push(p[i]);
			if(want==3) q3.push(p[i]);
			ans+=1ll*(-1)*p[i].a[1].fi;
			if(num[want]>n/2)
			{
				if(want==1)
				{
					ren xian=q1.top();
					q1.pop();
					ans-=xian.cha;
					xian.nowei++;
					if(xian.nowei==2)
					{
						xian.cha=1ll*(-1)*xian.a[2].fi-(-1)*xian.a[3].fi;
						if(xian.a[2].se==1) q1.push(xian);
						if(xian.a[2].se==2) q2.push(xian);
						if(xian.a[2].se==3) q3.push(xian);
					}
					if(xian.nowei==3)
					{
						xian.cha=0x3f3f3f3f;
						if(xian.a[3].se==1) q1.push(xian);
						if(xian.a[3].se==2) q2.push(xian);
						if(xian.a[3].se==3) q3.push(xian);
					}
				}
				else if(want==2)
				{
					ren xian=q2.top();
					q2.pop();
					ans-=xian.cha;
					xian.nowei++;
					if(xian.nowei==2)
					{
						xian.cha=1ll*(-1)*xian.a[2].fi-(-1)*xian.a[3].fi;
						if(xian.a[2].se==1) q1.push(xian);
						if(xian.a[2].se==2) q2.push(xian);
						if(xian.a[2].se==3) q3.push(xian);
					}
					if(xian.nowei==3)
					{
						xian.cha=0x3f3f3f3f;
						if(xian.a[3].se==1) q1.push(xian);
						if(xian.a[3].se==2) q2.push(xian);
						if(xian.a[3].se==3) q3.push(xian);
					}
				} 
				else if(want==3)
				{
					ren xian=q3.top();
					q3.pop();
					ans-=xian.cha;
					xian.nowei++;
					if(xian.nowei==2)
					{
						xian.cha=1ll*(-1)*xian.a[2].fi-(-1)*xian.a[3].fi;
						if(xian.a[2].se==1) q1.push(xian);
						if(xian.a[2].se==2) q2.push(xian);
						if(xian.a[2].se==3) q3.push(xian);
					}
					if(xian.nowei==3)
					{
						xian.cha=0x3f3f3f3f;
						if(xian.a[3].se==1) q1.push(xian);
						if(xian.a[3].se==2) q2.push(xian);
						if(xian.a[3].se==3) q3.push(xian);
					}					
				}
			}
		}
		cout<<ans<<endl;

	}
	
	
//	cerr<<1.0*(clock()-sti)/CLOCKS_PER_SEC<<endl;
return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0



*/
