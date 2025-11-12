// SN-J00700 niujunxiang
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a,ji=0,nn,mm;
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++)
	{
		int b;
		cin>>b;
		if(b>a) ji++;
	}
	ji++;
	if(ji%n==0)
	{
		cout<<ji/n<<" ";
		if((ji/n)%2==0) cout<<1;
		else cout<<n;
	}
	else
	{
		nn=ji/n+1;
		mm=ji%n;
		cout<<nn<<" ";
		if(nn%2==0)	cout<<n-mm+1;
		else cout<<mm;
	}
	return 0;
}
