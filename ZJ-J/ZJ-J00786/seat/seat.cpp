#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501],ks,kh;
long long fx=1,x=1,y=1;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long k=n*m;
	for(int i=1;i<=k;++i)cin>>a[i];
	ks=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;++i)
	{
		if(a[i]==ks)
		{
			kh=i;
			break;
		}
	}
	while(1)
	{
		kh--;
		if(kh==0)break;
		if(fx==1)x++;
		else if(fx==2)y++;
		else if(fx==3)x--;
		if(fx==2)
		{
			if(y%2==0)fx=3;
			else if(y%2==1)fx=1;
		}
		else if(x==n)fx=2;
		else if(x==1)fx=2;
	}
	cout<<y<<" "<<x;
	return 0;
}