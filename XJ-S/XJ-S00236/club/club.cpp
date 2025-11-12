#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
struct node{
	int u;int x;int y;int z;
};
int a[N][5],f[5],a1[N];
vector<node> v;
int n,t,ans=-1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,k,x,y,z;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]) f[j]++;
				if(j==1) a1[i]=a[i][j];
			}
		}
		if(f[2]==0&&f[3]==0)
		{
			ans=0;
			sort(a1+1,a1+n+1);
			for(i=n;i>=n/2;i++)
			{
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			v.push_back({0,0,0,0});
			for(i=1;i<=n;i++)
	    	{
	    		int s=v.size();
		    	for(j=1;j<=3;j++)
	    		{
			         for(k=0;k<s;k++)
			         {
			         	if(j==1&&v[k].x<n/2)
			         	{
			         		ans=max(ans,v[k].u+a[i][j]);
			         		v.push_back({v[k].u+a[i][j],v[k].x+1,v[k].y,v[k].z});
						}
			         	else if(j==2&&v[k].y<n/2)
			         	{
			         		ans=max(ans,v[k].u+a[i][j]);
			         		v.push_back({v[k].u+a[i][j],v[k].x,v[k].y+1,v[k].z});
						}
			         	else if(j==3&&v[k].z<n/2)
			         	{
			         		ans=max(ans,v[k].u+a[i][j]);
			         		v.push_back({v[k].u+a[i][j],v[k].x,v[k].y,v[k].z+1});
						}						
					 }
	    		}
	    	}
	    	cout<<ans<<endl;
	    	v.clear();
		}
		ans=-1;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
	}
	return 0;
} 
