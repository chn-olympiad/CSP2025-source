#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100050];
bool cmp(node q,node p)
{
	return q.x>p.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
		   cin>>a[i].x>>a[i].y>>a[i].z;
		   if(a[i].y==0) cnt2++;
		   else if(a[i].z==0) cnt3++;
		}
		if(n==2) 
		{
			int h1=a[1].x+a[2].y;
			int h2=a[1].x+a[2].z;
			int h3=a[1].y+a[2].x;
			int h4=a[1].y+a[2].z;
			int h5=a[1].z+a[2].x;
			int h6=a[1].z+a[2].y;
			cout<<max(max(max(h1,h2),max(h3,h4)),max(h5,h6));
		}
		if(cnt2==n&&cnt3==n)
		{
			int s=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			    s+=a[i].x;
			cout<<s;
		}
	}
	return 0;
}
