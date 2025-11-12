#include <iostream>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int s=1;
	int a[105];
	int n , m;
	cin >> n >> m;
	for(int i=0;i<n*m;i++)
	{
		cin >> a[i];
	}
	if(m%2==0)
	{
		cout << s << m;
	}
	else
		cout << n << ' ' <<  m;
	return 0;
}
