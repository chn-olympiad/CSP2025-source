//SN-J01084 menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[110],len,r;
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+len,cmp);
	int nowx=1,nowy=1;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==r)
		{
			cout<<nowx<<" "<<nowy;
			return 0;
		}
		if((nowx&1)&&(nowy==n))
			nowx++;
		else if((nowx&1))
			nowy++;
		else if((nowy==1))
			nowx++;
		else
			nowy--;
	}
	return 0;
}
