#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100001][3];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[3];
int ans;
int input()
{
	int x=0;
	while(1)
	{
		char ch=getchar();
		if(ch==' '||ch=='\n') return x;
		x=x*10+ch-'0';
	}
}
void print(int x)
{
	int a[15],l=0;
	while(x!=0)
	{
		a[l++]=x%10;
		x/=10;
	}
	for(int i=l-1;i>=0;i--) putchar(a[i]+'0');
	putchar('\n');
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=input();
	while(t--)
	{
		while(q[0].size()) q[0].pop();
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		ans=0;
		n=input();
		for(int i=1;i<=n;i++) a[i][0]=input(),a[i][1]=input(),a[i][2]=input();
		for(int i=1;i<=n;i++)
		{
			int Max=a[i][0],p1=0,p2;
			if(Max<a[i][1]) Max=a[i][1],p1=1;
			if(Max<a[i][2]) Max=a[i][2],p1=2;
			Max=-1;
			if(0!=p1&&Max<a[i][0]) Max=a[i][0],p2=0;
			if(1!=p1&&Max<a[i][1]) Max=a[i][1],p2=1;
			if(2!=p1&&Max<a[i][2]) Max=a[i][2],p2=2;
			if(q[p1].size()<n/2) q[p1].push(make_pair(a[i][p1]-a[i][p2],i)),ans+=a[i][p1];
			else if(a[i][p1]-q[p1].top().first>=a[i][p2])
			{
				ans+=(a[i][p1]-q[p1].top().first);
				q[p1].pop();
				q[p1].push(make_pair(a[i][p1]-a[i][p2],i));
			}
			else ans+=a[i][p2];
		}
		print(ans);
	}
	return 0;
}
