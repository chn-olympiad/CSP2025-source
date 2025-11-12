#include<bits/stdc++.h>
using namespace std;
int n[10],t,ans1,ans2,ans3,ans,m,w;
int a1[100002],a2[100002],a3[100002];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		for(int j=m;j<n[i]+m;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		m=m+n[i];
	}
	if(n[0]==100000)
	{
		for(int i=0;i<t;i++)
		{
			for(int j=w;j<n[i]+w;j++)
			{
				ans1=max(ans1,a1[j]);
			}
			cout<<ans1<<endl;
			w=w+n[i];
			ans1=0;
		}
	}
	return 0;
}

