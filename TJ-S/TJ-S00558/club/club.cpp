#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int po1,po2,po3,pj,jh,mx,pos;
}nd[10000001];
bool cmp(node a,node b)
{
	return a.po1>b.po1;
}
bool cmp1(node a,node b)
{
	if(a.pj==b.pj) return a.jh>b.jh;
	else return a.pj>b.pj;
}
long long t;
long long n;
long long maxn=-2;
long long sum;
long long pos[10];
long long cj[10000001];
long long ch[10001][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n;
		for(long long j=1;j<=n;j++)
		{
			cin>>nd[j].po1>>nd[j].po2>>nd[j].po3;
		}
		if(nd[1].po2==0&&nd[1].po3==0&&nd[2].po2==0&&nd[2].po3==0&&nd[3].po2==0&&nd[3].po3==0&&nd[4].po2==0&&nd[4].po3==0&&nd[5].po2==0&&nd[5].po3==0&&nd[6].po2==0&&nd[6].po3==0&&nd[7].po2==0&&nd[7].po3==0)
		{
			sort(nd+1,nd+n+1,cmp);
			for(long long j=1;j<=n/2;j++)
			{
				sum+=nd[j].po1;
			}
			cout<<sum;
		}
		else if(nd[1].po3==0&&nd[2].po3==0&&nd[3].po3==0&&nd[4].po3==0&&nd[5].po3==0&&nd[6].po3==0&&nd[7].po3==0&&nd[8].po3==0&&nd[9].po3==0&&nd[10].po3==0&&nd[11].po3==0&&nd[12].po3==0)
		{
			for(long long j=1;j<=n;j++)
			{
				if(nd[i].po1<nd[i].po2)
				{
					nd[i].pj=nd[i].po2-nd[i].po1;
				}
				else if(nd[i].po1>=nd[i].po2)
				{
					nd[i].pj=nd[i].po1-nd[i].po2;
				}
				nd[j].jh=nd[j].po1+nd[j].po2;
			}
			sort(nd+1,nd+n+1,cmp1);
			for(long long j=1;j<n;j++)
			{
				maxn=max(nd[j].po1,nd[j].po2);
				sum+=maxn;
			}
			cout<<sum;
		}
		else 
		{
			for(int j=1;j<=n;j++)
			{
				nd[j].mx=max(max(nd[i].po1,nd[i].po2),max(nd[i].po1,nd[i].po3));
				if(nd[j].mx==nd[j].po1)
				{
					pos[1]++;
				}
				else if(nd[j].mx==nd[j].po2)
				{
					pos[2]++;
				}
				else if(nd[j].mx==nd[j].po3)
				{
					pos[3]++;
				}
			}
			if(pos[1]<=n/2&&pos[2]<=n/2&&pos[3]<=n/2)
			{
				for(int j=1;j<=n;j++)
				{
					sum+=nd[j].mx;
				}
				cout<<sum;
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					ch[j][1]=nd[j].po1;
					ch[j][2]=nd[j].po2;
					ch[j][3]=nd[j].po3;
				}
				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
