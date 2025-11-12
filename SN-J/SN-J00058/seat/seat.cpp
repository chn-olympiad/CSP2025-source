#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,s;
	cin>>n>>m;
	s=n*m;
	int a[0];
	for(int i=1; i<=s; i++){
		cin>>a[i];
		sort(a[0],a[s]);
	}
	
	return 0;
}
