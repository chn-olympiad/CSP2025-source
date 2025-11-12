	#include<bits/stdc++.h>
//	#define int long long
	using namespace std;
	const int N=1e5+1;
	int n,m,a1,a,q,ax,ay;
	signed main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		cin>>a1;
		for(int i=2;i<=n*m;i++)
		{
			cin>>a;
			if(a>a1)
			{
				q++;
			}
		}
		q++;
		ay=(q%n==0?q/n:q/n+1);
		ax=(q%n==0?n:q%n);
		ax=(ay%2==1?ax:n+1-ax);
		cout<<ay<<" "<<ax;
		return 0;
	}
	/*
	2 2 99 100 97 98
	2 2
	98 99 100 97
	3 3 94 95 96 97 98 99 100 93 92

	*/
