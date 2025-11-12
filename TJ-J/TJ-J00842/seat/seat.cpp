#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,a[105];
	cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
    	for(int i=1;i<=m;i++)
    	{
    		cout << a[i];
		}
	}
	sort(a+1,a+n+1);
	
	return 0;
}
