#include<bits/stdc++.h>
using namespace std;
int a[500050];
int b[500050];
int c[500050];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
