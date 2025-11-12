#include <iostream>
using namespace std;
int main()	
{
	freopen('polygon.in','r',std.in);
	freopen('polygon.out','w',std.out);
	int n,s,a = 0;
	cin >> n >> s;
	for(int i = 0;i < n;i++)
	{
		if(s * 2 > n)
		{
			a += 1;
		}
	}
	cout << a;
	return 0;
}
