#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100005]; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,o,p,q,sumo,sump,sumq;
	cin >> t;
	while(t--)
	{
		sumo=sump=sumq;
		cin >> n;
		o=p=q=n/2;
		for (int i = 1; i<= n; i++)
		{
			cin >> a[i].x>>a[i].y>>a[i].z;
		}
		if (n==2)
		{
			int w=max(a[1].x+a[2].y,a[1].x+a[2].z);
			int u=max(a[1].y+a[2].x,a[1].y+a[2].z);
			int s=max(a[1].z+a[2].x,a[1].z+a[2].y);
			cout << max(w,max(u,s));
			return 0;
		}
		for (int i = 1; i<= n; i++)
		{
			if (q >= 0)
			{
				if (a[i].x==0&&a[i].y==0)
				{
					q--;
					sumq+=a[i].z;
				} 
				 
			}
			if (p>=0)
			{
				if (a[i].x==0&&a[i].z==0)
				{
					p--;
					sumq+=a[i].y;
				} 
			}
			if (o >= 0)
			{
				if (a[i].z==0&&a[i].y==0)
				{
					o--;
					sumo+=a[i].x;
				} 
			}
		} 
		cout << sump+sumq+sumo<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
