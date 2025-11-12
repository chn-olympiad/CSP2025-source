#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,p[100000]={0};
	cin>>t;
	while(t--)
	{
		int n;cin>>n;int maxx=0,a[4][10000]={0};int pos=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			p[i]=a[1][i];
			if(a[2][i]!=0||a[3][i]!=0)
			{
				pos=0;
			}
			maxx+=max(a[1][i],max(a[2][i],a[3][i]));
		}
		if(pos)
		{
			sort(p+1,p+n+1,cmp);int sum=0;
			for(int i=1;i<=n/2;i++)
			{
				sum+=p[i];
			}
			cout<<sum;
			return 0;
		}
		cout<<maxx<<endl;
		return 0;
	}
	ios::sync_with_stdio(0);
	return 0;
	
}
