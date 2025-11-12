#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool cmp(int m,int n)
{
	return m>n;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n,na=0,nb=0,nc=0;
		cin >> n;
		
		if(n==2) 
		{
			int a[10]={0};int b[10]={0};int c[10]={0};
			for(int j=1;j<=n;j++)
			{
				cin >> a[j] >> b[j] >> c[j];
			}
			int ans[100];
			ans[0]=a[1]+b[2],ans[1]=a[1]+c[2],ans[2]=b[1]+a[2],ans[3]=b[1]+c[2],ans[4]=c[1]+a[2],ans[5]=c[1]+b[2];
			sort(ans,ans+6,cmp);
			cout << ans[0] <<endl;
		}
		else
		{
			priority_queue <int> a;
			priority_queue <int> b;
			priority_queue <int> c;
			for(int j=1;j<=n;j++)
			{
				int x,y,z;
				cin >> x >> y >> z;
				a.push(x) , b.push(y) , c.push(z);
			}
			if(b.top()==0 && c.top()==0)
			{
				long long ans=0;
				for(int j=1;j<=(n/2);j++) 
				{
					ans=ans+a.top();
					a.pop();
				}
				cout << ans <<endl;
			}
		}
	}
	return 0;
}
