#include<bits/stdc++.h> 
using namespace std;
int t,s=0;
int m[100050][5];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		int a[100050],b[100050],c[100050];
		int a1,b1,c1;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[j]=x;
			b[j]=y;
			c[j]=z;
			a1+=x;
			b1+=y;
			c1+=z;
		}
		if(b1==0&&c1==0)
		{
			sort(a,a+n);
			for(int k=n/2;k<n;k++)
			{
				s+=a[k];
			}
			cout<<s;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		s=0;
	}
	return 0;
}
