#include <iostream>
using namespace std;
int n,a[100],r[100],l[100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> r[i] >> l[i];
	}
	cout << a[n];
	return 0;
}
