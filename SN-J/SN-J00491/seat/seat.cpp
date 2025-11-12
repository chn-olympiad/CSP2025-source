#include <iostream>
using namespace std;
int main()
{
	freopen('seat.in',r,'std.in');
	freopen('seat.out',w,'std.out');
	int n,m,c,r,s,b;
	cin >> n >> m >> c >> r >> s >> b;
	cout << (n - c) << r;
	return 0;
}  
