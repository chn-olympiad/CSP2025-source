#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[100005][5];
int n,ans=0,x;
void f(int i,int a,int b,int c,int sum)
{
	if(i>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a<x)	f(i+1,a+1,b,c,sum+d[i][1]);
	if(b<x)	f(i+1,a,b+1,c,sum+d[i][2]);
	if(c<x) f(i+1,a,b,c+1,sum+d[i][3]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=n/2;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>d[i][j];
		f(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 