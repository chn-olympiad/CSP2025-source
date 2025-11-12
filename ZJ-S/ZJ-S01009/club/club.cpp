#include<bits/stdc++.h>
#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freio(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
using namespace std;
const int N=1e5+5;
long long T;
long long n;
struct node
{
	signed long long x;
	signed long long y;
	signed long long z;
	signed long long flag;
	signed long long deltaxy;
	signed long long deltaxz;
	signed long long deltayz;
}a;
node x[N];
node y[N];
node z[N];
bool cmp1(node a,node b);
bool cmp2(node a,node b);
bool cmp3(node a,node b);
//RP++
//16:30 90?
int main()
{
	fastio
	freio("club")
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
//	freopen("club2.in","r",stdin);
//	freopen("club2.out","w",stdout);
//	freopen("club3.in","r",stdin);
//	freopen("club3.out","w",stdout);
//	freopen("club4.in","r",stdin);
//	freopen("club4.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("club5.out","w",stdout);
	cin>>T;
	while(T--)
	{
		signed long long sum=0;
		signed long long sum1=0;
		signed long long sum2=0;
		signed long long sum3=0;
		cin>>n;
		for(signed long long i=1;i<=n;i++)
		{
			cin>>a.x>>a.y>>a.z;
			a.deltaxy=a.x-a.y;
			a.deltaxz=a.x-a.z;
			a.deltayz=a.y-a.z;
			signed long long maxa=max(a.x,max(a.y,a.z));
			if(a.x==maxa)
			{
				sum1++;
				x[sum1].x=a.x;
				x[sum1].y=a.y;
				x[sum1].z=a.z;
				x[sum1].deltaxy=a.deltaxy;
				x[sum1].deltaxz=a.deltaxz;
				x[sum1].deltayz=a.deltayz;
				x[sum1].flag=1;
			}
			else if(a.y==maxa)
			{
				sum2++;
				y[sum2].x=a.x;
				y[sum2].y=a.y;
				y[sum2].z=a.z;
				y[sum2].deltaxy=a.deltaxy;
				y[sum2].deltaxz=a.deltaxz;
				y[sum2].deltayz=a.deltayz;
				y[sum2].flag=2;
			}
			else
			{
				sum3++;
				z[sum3].x=a.x;
				z[sum3].y=a.y;
				z[sum3].z=a.z;
				z[sum3].deltaxy=a.deltaxy;
				z[sum3].deltaxz=a.deltaxz;
				z[sum3].deltayz=a.deltayz;
				z[sum3].flag=3;
			}
		}
		if(sum1>(n/2))
		{
			signed long long morea=sum1-(n/2);
			signed long long lessb=(n/2)-sum2;
			signed long long lessc=(n/2)-sum3;
			sort(x+1,x+sum1+1,cmp1);
			if(morea<=lessb)
			{
				for(signed long long i=1;i<=morea;i++)
				{
					x[i].flag=2;
				}
			}
			else
			{
				for(signed long long i=1;i<=lessb;i++)
				{
					x[i].flag=2;
				}
				for(signed long long i=lessb+1;i<=morea;i++)
				{
					x[i].flag=3;
				}
			}
		}
		else if(sum2>(n/2))
		{
			signed long long moreb=sum2-(n/2);
			signed long long lessa=(n/2)-sum1;
			signed long long lessc=(n/2)-sum3;
			sort(y+1,y+sum2+1,cmp2);
			if(moreb<=lessa)
			{
				for(signed long long i=1;i<=moreb;i++)
				{
					y[i].flag=1;
				}
			}
			else
			{
				for(signed long long i=1;i<=lessa;i++)
				{
					y[i].flag=1;
				}
				for(signed long long i=lessa+1;i<=moreb;i++)
				{
					y[i].flag=3;
				}
			}
		}
		else if(sum3>(n/2))
		{
			signed long long morec=sum3-(n/2);
			signed long long lessa=(n/2)-sum1;
			signed long long lessb=(n/2)-sum2;
			sort(z+1,z+sum3+1,cmp3);
			if(morec<=lessa)
			{
				for(signed long long i=1;i<=morec;i++)
				{
					z[i].flag=1;
				}
			}
			else
			{
				for(signed long long i=1;i<=lessa;i++)
				{
					z[i].flag=1;
				}
				for(signed long long i=lessa+1;i<=morec;i++)
				{
					z[i].flag=2;
				}
			}
		}
		for(signed long long i=1;i<=sum1;i++)
		{
			if(x[i].flag==1)
			{
				sum+=x[i].x;
			}
			else if(x[i].flag==2)
			{
				sum+=x[i].y;
			}
			else
			{
				sum+=x[i].z;
			}
		}
		for(signed long long i=1;i<=sum2;i++)
		{
			if(y[i].flag==1)
			{
				sum+=y[i].x;
			}
			else if(y[i].flag==2)
			{
				sum+=y[i].y;
			}
			else
			{
				sum+=y[i].z;
			}
		}
		for(signed long long i=1;i<=sum3;i++)
		{
			if(z[i].flag==1)
			{
				sum+=z[i].x;
			}
			else if(z[i].flag==2)
			{
				sum+=z[i].y;
			}
			else
			{
				sum+=z[i].z;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
bool cmp1(node a,node b)
{
	if(a.deltaxy<b.deltaxy)
	{
		return true;
	}
	if(a.deltaxy==b.deltaxy)
	{
		if(a.deltaxz<b.deltaxz)
		{
			return true;
		}
	}
	return false;
}
bool cmp2(node a,node b)
{
	if(-(a.deltaxy)<-(b.deltaxy))
	{
		return true;
	}
	if(-(a.deltaxy)==-(b.deltaxy))
	{
		if(a.deltayz<b.deltayz)
		{
			return true;
		}
	}
	return false;
}
bool cmp3(node a,node b)
{
	if(-(a.deltaxz)<-(b.deltaxz))
	{
		return true;
	}
	if(-(a.deltaxz)==-(b.deltaxz))
	{
		if(-(a.deltayz)<-(b.deltayz))
		{
			return true;
		}
	}
	return false;
}
/*
18
4
13

132072
125098
147859
150176
158541
WA =(

447450
417649
473417
443896
484387

2211746
2527345
2706385
2710832
2861471

1499392690
1500160377
1499846353
1499268379
1500579370

It seems that I'm not a good OIer......
But I love OI at all.
I love C++ a lot.
However I don't have more time to study it now.
Wish good luck.
					--CN_emo_ 2025/11/1
*/