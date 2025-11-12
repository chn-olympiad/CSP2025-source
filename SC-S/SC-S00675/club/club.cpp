#include <bits/stdc++.h>
using namespace std;

int T,n;
struct per{
	int a[4],s[4];
}p[100005];

per d(per q)
{
	if(q.a[1]>=q.a[2] and q.a[1]>=q.a[3])
	{
		q.s[1]=1;
		if(q.a[2]>=q.a[3])
			q.s[2]=2;
		else
		{
			q.s[2]=3;
			swap(q.a[2],q.a[3]);
		}
	}
	if(q.a[2]>=q.a[1] and q.a[2]>=q.a[3])
	{
		q.s[1]=2;
		swap(q.a[1],q.a[2]);
		if(q.a[1]>=q.a[3])
			q.s[2]=1;
		else
		{
			q.s[2]=3;
			swap(q.a[2],q.a[3]);
		}
	}
	if(q.a[3]>=q.a[1] and q.a[3]>=q.a[2])
	{
		q.s[1]=3;
		swap(q.a[1],q.a[3]);
		if(q.a[2]>q.a[1])
			q.s[2]=2;
		else
		{
			q.s[2]=1;
			swap(q.a[2],q.a[3]);
		}
	}
	return q;
}

bool cmp(per q1,per q2)
{
	return (q1.a[1]-q1.a[2])<=(q2.a[1]-q2.a[2]);
}

int t[4]={};
per x[4][100005]={};
int ans=0;

signed int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t[1]=t[2]=t[3]=0;
		ans=0;
		per kp;
		kp.a[1]=kp.a[2]=kp.a[3]=kp.s[1]=kp.s[2]=kp.s[3]=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=n;j++)
				x[i][j]=kp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
			p[i]=d(p[i]);
			x[p[i].s[1]][++t[p[i].s[1]]]=p[i];
			ans+=p[i].a[1];
		}
		int m=1;
		while(m<4 and t[m++]<=n/2);
		if(t[--m]>n/2)
		{
			sort(x[m]+1,x[m]+t[m]+1,cmp);
			int f=1;
			while(t[m]>n/2)
			{
				t[m]--;
				per np=x[m][f++];
				ans=ans-np.a[1]+np.a[2];
			}
		}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 