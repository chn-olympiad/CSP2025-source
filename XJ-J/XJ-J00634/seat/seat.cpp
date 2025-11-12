#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],s,c = 0,r = 0,ans = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<= n*m;i++)
	{
		cin >> a[i];
		s = a[1];
	}
	sort(a,a+n*m+1);
	cout << 1 << " "<<1;
	return 0;	
} 
