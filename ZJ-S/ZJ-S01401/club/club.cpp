#include <bits/stdc++.h>
using namespace std;
long long t,n,halfn,a[1000003][4],c[4],sums;
struct clubnewsf
{
	long long f;
	long long fv;
	bool flagf = true;
	int ls;
}newsf[1000003];
struct clubnewss
{
	long long s;
	long long sv;
	bool flags = true;
	int ls1;
}newss[1000003];
struct clubnewsth
{
	long long th;
	long long thv;
	bool flagth = true;
	int ls2;
}newsth[1000003];
void pd(long long a1,long long a2,long long a3,int j)
{
	if(a1>a2&&a2>=a3)
	{
		newsf[j].f=1;
		newsf[j].fv=a1;		
		newss[j].s=2;
		newss[j].sv=a2;
		newsth[j].th=3;
		newsth[j].thv=a3;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
	else if(a1>a3&&a3>=a2)
	{
		newsf[j].f=1;
		newsf[j].fv=a1;		
		newss[j].s=3;
		newss[j].sv=a3;
		newsth[j].th=2;
		newsth[j].thv=a2;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
	else if(a2>a1&&a1>=a3)
	{
		newsf[j].f=2;
		newsf[j].fv=a2;		
		newss[j].s=1;
		newss[j].sv=a1;
		newsth[j].th=3;
		newsth[j].thv=a3;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
	else if(a2>a3&&a3>=a1)
	{
		newsf[j].f=2;
		newsf[j].fv=a2;		
		newss[j].s=3;
		newss[j].sv=a3;
		newsth[j].th=1;
		newsth[j].thv=a1;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
	else if(a3>a2&&a2>=a1)
	{
		newsf[j].f=3;
		newsf[j].fv=a3;		
		newss[j].s=2;
		newss[j].sv=a2;
		newsth[j].th=1;
		newsth[j].thv=a1;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
	else if(a3>a1&&a1>=a2)
	{
		newsf[j].f=3;
		newsf[j].fv=a3;		
		newss[j].s=1;
		newss[j].sv=a1;
		newsth[j].th=2;
		newsth[j].thv=a2;
		newsf[j].flagf = true;
		newss[j].flags = true;
		newsth[j].flagth = true;
	}
}
int bfs(int c1,int c2,int c3,int all,int sum)
{
	c[1]=c1;
	c[2]=c2;
	c[3]=c3;
	if(all==n)
		return sum;
	if(c[newsf[all].f]<halfn&&newsf[all].flagf)
	{
		c[newsf[all].f]++;
		c1 = c[1];
		c2 = c[2];
		c3 = c[3];
		newsf[all].flagf = false;
		for(int i=0;i<n;i++)
		{
			if(newss[i].ls1 == newss[all].ls1)
				newss[all].flags = false;
			if(newsth[i].ls2 == newsth[all].ls2)
				newsth[all].flagth = false;				
		}
		bfs(c1,c2,c3,++all,sum+newsf[all].fv);		
	}
	else if(c[newss[all].s]<halfn&&newss[all].flags)
	{
		c[newss[all].s]++;
		c1 = c[1];
		c2 = c[2];
		c3 = c[3];
		newss[all].flags = false;
		for(int i=0;i<n;i++)
		{
			if(newsf[i].ls == newsf[all].ls)
				newsf[all].flagf = false;
			if(newsth[i].ls2 == newsth[all].ls2)
				newsth[all].flagth = false;				
		}
		bfs(c1,c2,c3,++all,sum+newss[all].sv);		
	}
	else if(c[newsth[all].th]<halfn&&newsth[all].flagth)
	{
		c[newsth[all].th]++;
		c1 = c[1];
		c2 = c[2];
		c3 = c[3];
		for(int i=0;i<n;i++)
		{
			if(newss[i].ls1 == newss[all].ls1)
				newss[all].flags = false;
			if(newsf[i].ls == newsf[all].ls)
				newsf[all].flagf = false;
		}
		newsth[all].flagth = false;
		bfs(c1,c2,c3,++all,sum+newsth[all].thv);		
	}
}
bool mycmpf(clubnewsf x,clubnewsf y)
{
	if(x.fv>y.fv)
		return true;
	return false;
}
bool mycmps(clubnewss x,clubnewss y)
{
	if(x.sv>y.sv)
		return true;
	return false;
}
bool mycmpth(clubnewsth x,clubnewsth y)
{
	if(x.thv>y.thv)
		return true;
	return false;
}
bool mycmpf1(clubnewsf x,clubnewsf y)
{
	if(x.fv<y.fv)
		return true;
	return false;
}
bool mycmps1(clubnewss x,clubnewss y)
{
	if(x.sv<y.sv)
		return true;
	return false;
}
bool mycmpth1(clubnewsth x,clubnewsth y)
{
	if(x.thv<y.thv)
		return true;
	return false;
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.txt","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		halfn=n/2;
		for(int j=0;j<n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			newsf[j].ls = j;
			newss[j].ls1 = j;
			newsth[j].ls2 = j;
			pd(a[j][1],a[j][2],a[j][3],j);
		}
		sort(newsf,newsf+n,mycmpf);
		sort(newss,newss+n,mycmps);
		sort(newsth,newsth+n,mycmpth);
		sums=bfs(0,0,0,0,0);
		cout<<sums<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}