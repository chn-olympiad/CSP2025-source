#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	long long k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,w=1,q=1;
	while(w<=n*m)
	{
		if(a[w]==k) 
		{
			cout<<y<<" "<<x;
			return 0;
		}
		q++;
//		cout<<q<<endl;
		if(q==n+1) y++;
		 else if(q==2*n+1) x=1,y++,q=1;
		  else x++;
		w++;
	//	cout<<x<<" "<<y<<endl;
	}
	return 0;
}
/*
4 4
96 97 98 95 94 97 99 100 101 99 100 90 91 94 95 97
*/