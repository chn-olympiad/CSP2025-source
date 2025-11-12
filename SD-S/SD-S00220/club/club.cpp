#include<bits/stdc++.h>
using namespace std;
char kinchar,kinf;
long long kinnum;
inline long long kin()
{
	kinf=1;
	kinchar=getchar();
	kinnum=0;
	if(!('0'<=kinchar&&kinchar<='9'))
	{
		kinf=-1;
		kinchar=getchar();
	}
	while(('0'<=kinchar&&kinchar<='9'))
	{
		kinnum=kinnum*10+kinchar-'0';
		kinchar=getchar();
	}
	return kinnum*kinf;
}
struct st
{
	long long a,b,c;
};
st l[100050];
long long n,t;
bool cmp(st a,st b)
{
	return a.a>b.a;
}
long long usd[10],maxxx,sum;
void dfs(long long p)
{
	long long maxx=0,num,ll[3],i;
	ll[1]=l[p].a;
	ll[2]=l[p].b;
	ll[3]=l[p].c;
	for(i=1;i<=3;i++)
	{
		if(usd[i]<(n>>1))
		{
			usd[i]++;
			sum+=ll[i];
			if(p==n)
			{
				if(sum>maxxx)
					maxxx=sum;
			}
			else
			{
				dfs(p+1);
			}
			sum-=ll[i];
			usd[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=kin();
	long long nn;
	long long maxx;
	while(t--)
	{
		n=kin();
		nn=n/2;
		for(int i=1;i<=n;i++)
		{
			l[i].a=kin();
			l[i].b=kin();
			l[i].c=kin();
		}
		if(n<=30)
		{
			dfs(1);
			cout<<maxxx<<'\n';
			
		}
		else
		{
			sort(l+1,l+1+n,cmp);
			long long sum=0;
			for(int i=1;i<=n;i++)
				sum+=l[i].a;
			cout<<sum<<'\n';
		}
	}

	

	fclose(stdin);
	fclose(stdout);
	return 0;
}

