#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int T,n;
struct node
{
	int x,y,z;
}a[N];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}	
		sort(a+1,a+n+1,cmp);
		int sum=a[1].x+a[2].x;
		cout<<sum<<endl;
	}
} 
