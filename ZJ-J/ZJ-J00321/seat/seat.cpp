#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105],aa,ii,n,m;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	aa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(aa==a[i])
		{
			ii=i;
			break;
		}
	}
	if(ii%n==0)
	{
		if((ii/n)%2==0)
		cout<<ii/n<<" "<<1;
		else
		cout<<ii/n<<" "<<n;
	}
	else if((ii/n)%2==1)
	cout<<(ii/n)+1<<" "<<n-(ii%n)+1;
	else
	cout<<(ii/n)+1<<" "<<ii%n;
	return 0;
}
//81 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 1 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100