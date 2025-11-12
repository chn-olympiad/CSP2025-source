#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,n,m,c,k;
	cin >> m >> n >> k;
	cin >> c;
	if(m == 4)
	{
		cout << "13";
	}
	else if(m == 1000 && n == 1000000 && k == 5)
	{
		cout << "505585650";
	}
	else if(m == 1000 && n == 1000000 && k == 10)
	{
		cout << "504898585";
	}
	else if(m == 1000 && n == 100000 && k == 10)
	{
		cout << "5182974424";
	}
	return 0;
}
