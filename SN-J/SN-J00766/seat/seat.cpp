#include <iostream>
using namespace std;
int n,m,s[100]
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> s[i];
	}
	cout << (s[n] + s[m]);
	return 0;
}
