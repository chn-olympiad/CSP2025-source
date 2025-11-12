#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct node
{
	long long z,cha;	
};
long long t,n;
node aaa[100005];
node bbb[100005];
node ccc[100005];
bool cmp(node x,node y)
{
	return x.cha<y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long zu1=0,zu2=0,zu3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			long long q,w,e;
			cin>>q>>w>>e;
			if(q>=w&&q>=e)
			{
				ans+=q;
				zu1++;
				aaa[zu1].z=q;
				aaa[zu1].cha=min(q-w,q-e);
			}
			else if(w>=q&&w>=e)
			{
				ans+=w;
				zu2++;
				bbb[zu2].z=w;
				bbb[zu2].cha=min(w-q,w-e);
			}
			else if(e>=q&&e>=w)
			{
				ans+=e;
				zu3++;
				ccc[zu3].z=e;
				ccc[zu3].cha=min(e-q,e-w);
			}
		}
		if(zu1>n/2)
		{
			sort(aaa+1,aaa+zu1+1,cmp);
			for(int i=1;i<=zu1-n/2;i++)
			{
				ans-=aaa[i].cha;
			}
		}
		else if(zu2>n/2)
		{
			sort(bbb+1,bbb+zu2+1,cmp);
			for(int i=1;i<=zu2-n/2;i++)
			{
				ans-=bbb[i].cha;
			}
		}
		else if(zu3>n/2)
		{
			sort(ccc+1,ccc+zu3+1,cmp);
			for(int i=1;i<=zu3-n/2;i++)
			{
				ans-=ccc[i].cha;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			aaa[i].z=aaa[i].cha=0;
			bbb[i].z=bbb[i].cha=0;
			ccc[i].z=ccc[i].cha=0;
		}
	}
	return 0;
}

