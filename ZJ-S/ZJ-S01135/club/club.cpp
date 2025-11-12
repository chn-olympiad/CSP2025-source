#include<bits/stdc++.h>
using namespace std;
struct a1{
	int x,y,z;
}a[100005];
bool cmp(a1 o,a1 p)
{
	return o.x>p.x;
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
		for(int i=1;i<=n;i++)
				cin>>a[i].x>>a[i].y>>a[i].z;
		if(n==2)
		{
			int maxx=max(a[1].x,a[2].x);
			int maxy=max(a[1].y,a[2].y);
			int maxz=max(a[1].z,a[2].z);
			if(maxx<maxy)
				swap(maxx,maxy);
			if(maxy<maxz)
				swap(maxy,maxz);
			if(maxx<maxz)
				swap(maxx,maxz);
			cout<<maxx+maxy<<endl;
		}
		else
		{
			
			sort(a+1,a+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++)
				sum+=a[i].x;
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
