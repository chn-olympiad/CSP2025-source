#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct node
{
	long long num[5],id;
}a[100050];

bool cmp1(node a,node b)
{
	if(a.num[1]>b.num[1])
	{
		return true;
	}
}
bool cmp2(node a,node b)
{
	if(a.num[2]>b.num[2])
	{
		return true;
	}
}
bool cmp3(node a,node b)
{
	if(a.num[3]>b.num[3])
	{
		return true;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		long long cnt=0,cntnum=0;
		cin>>n;
		long long sn=n/2;
		for(long long j=1;j<=n;j++)
		{
			for(long long k=1;k<=3;k++)
			{
				cin>>a[j].num[k];
			}
		}
		sort(a+1,a+1+n,cmp1);
		long long nowcnt=0,nowid=0;
		for(long long j=1;j<=sn;j++)
		{
			nowcnt=0;
			long long k=1; 
			for(k=1;k<=j;k++)
			{
				nowcnt+=a[k].num[1];
			}
			if(cnt<nowcnt)
			{
				cnt=nowcnt;
				nowid=k;
			}	
		}
		for(long long j=1;j<=nowid;j++)
		{
			a[j].num[1]= -100; 
			a[j].num[2]= -100; 
			a[j].num[3]= -100; 
		}
		cntnum+=cnt;
		sort(a+1,a+1+n,cmp2);
		nowid=0,cnt=0;
		for(long long j=1;j<=sn;j++)
		{
			nowcnt=0;
			long long k;
			for(k=1;k<=j;k++)
			{
				nowcnt+=a[k].num[2];
			}
			if(cnt<nowcnt)
			{
				cnt=nowcnt;
				nowid=k;
			}
		}
		for(long long j=1;j<=nowid;j++)
		{
			a[j].num[1]= -100; 
			a[j].num[2]= -100; 
			a[j].num[3]= -100;
		}
		cntnum+=cnt;
		sort(a+1,a+1+n,cmp3);
		nowid=0,cnt=0;
		for(long long j=1;j<=sn;j++)
		{
			nowcnt=0;
			long long k;
			for(k=1;k<=j;k++)
			{
				nowcnt+=a[k].num[3];
			}
			if(cnt<nowcnt)
			{
				cnt=nowcnt;
				nowid=k;
			} 
		}
		
		cntnum+=cnt;
		cout<<cntnum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
