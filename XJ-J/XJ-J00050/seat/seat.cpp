#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,c,r;
	cin >> n >> m >> a1;
	if (n*m%2==0)
	{
		if (a1%2==0)
		{
			cout << 2 << " " << 2;
		}
		else
		{
			cout << 1 << " " << 2;
		}
	}
	else
	{
		cout << 3 << " " << 1;
	}
}
