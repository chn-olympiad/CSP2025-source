#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[11][11];
int r(int x,int y)
{
	int t=(rand()<<15)+rand();
	return t%(y-x+1)+x;
}
signed main()
{
	freopen("road.in","w",stdout);
	srand(time(0));
	int n=r(1,10),m=r(n,10),k=r(1,10);
	cout<<n<<" "<<m<<" "<<k<<endl;
	for(int i=1;i<=m;i++)
	{
		int x=r(1,n),y=r(1,n);
		while(s[x][y]||x==y)
			x=r(1,n),y=r(1,n);
		s[x][y]=1;
		cout<<x<<" "<<y<<" "<<r(1,100)<<endl;
	}
	for(int i=1;i<=k;i++)
	{
		cout<<r(1,100)<<" ";
		for(int j=1;j<=n;j++) cout<<r(1,100)<<" ";
		cout<<endl;
	}
	return 0;
}
