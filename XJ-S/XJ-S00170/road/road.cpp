#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,b[1000005],l,r,k,p[1000005],q[1000005],x,y,c[1005][1005],s;
struct node
{
	long long int x,y,z;
}a[1000005];
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
	cin>>a[i].x>>a[i].y>>a[i].z;
	c[a[i].x][a[i].y]=a[i].z;
    }
	for(i=1;i<=k;i++)
	{
	cin>>p[1];
	for(j=1;j<=n;j++)
	cin>>q[i];
    }
    for(i=1;i<=k;i++)
    {
    	l+=p[i];
    	for(j=1;j<=n;j++)
    	{
    		r+=q[i];
		}
	}
	if(l==0&&r==0)
	{
		cout<<0;
		return 0;
	}
	if(k==0)
	{
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n-1;i++)
		{
			s+=a[i].z;
		}
	}
	cout<<s;
	return 0;
}

