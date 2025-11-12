#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int f,s,t;
}sd[101000];
int c1[101000],c2[101000],c3[101000],t[101000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ti,n;
	scanf("%d",&ti);
	for(int i=1;i<=ti;i++)
	{
		c1[0]=0;
		c2[0]=0;
		c3[0]=0;
		long long int cnt=0;
		cin>>n;
		for(int l=1;l<=n;l++)
		{
			scanf("%d %d %d",&sd[l].f,&sd[l].s,&sd[l].t);
			if(sd[l].f>=sd[l].s&&sd[l].f>=sd[l].t)
			{
				cnt+=sd[l].f;
				c1[0]++;
				c1[c1[0]]=l;
				}	
			else if(sd[l].s>=sd[l].f&&sd[l].s>=sd[l].t)	
			{
				cnt+=sd[l].s;
				c2[0]++;
				c2[c2[0]]=l;
			}
			else if(sd[l].t>=sd[l].f&&sd[l].t>=sd[l].s)	
			{
				cnt+=sd[l].t;
				c3[0]++;
				c3[c3[0]]=l;
			}
		}
		if(c1[0]>n/2)
		{
			t[0]=c1[0];
			for(int j=1;j<=c1[0];j++)
			{
				int tp1=abs(sd[c1[j]].f-sd[c1[j]].s),tp2=abs(sd[c1[j]].f-sd[c1[j]].t);
				t[j]=min(tp1,tp2);
			}
		}
		else if(c2[0]>n/2)
		{
			t[0]=c2[0];
			for(int j=1;j<=c2[0];j++)
			{
				int tp1=abs(sd[c2[j]].s-sd[c2[j]].f),tp2=abs(sd[c2[j]].s-sd[c2[j]].t);
				t[j]=min(tp1,tp2);
			}
		}
		else if(c3[0]>n/2)
		{
			t[0]=c3[0];
			for(int j=1;j<=c3[0];j++)
			{
				int tp1=abs(sd[c3[j]].t-sd[c3[j]].f),tp2=abs(sd[c3[j]].t-sd[c3[j]].s);
				t[j]=min(tp1,tp2);
			}
		}
		sort(t+1,t+t[0]+1);
		for(int k=1;k<=max(c3[0],max(c1[0],c2[0]))-n/2;k++)
		{
			cnt=cnt-t[k];
		}
		cout<<cnt<<endl;
	}
	return 0;
}
