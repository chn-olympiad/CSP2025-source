//SN-J00460  把小煜  西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
//#define int unsigned long long
using namespace std;
int n,m;
int a[110],b,x[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(j&1) x[i][j]=a[(j-1)*n+i];
		else x[i][j]=a[j*n-i+1];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(x[i][j]==b)
		{
			cout<<j<<" "<<i;
			return 0;
		}
	return 0;
}
