#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
		k += (a[i]>=a[1]);
	}
	int ans[2] = {(k-1)/n};
	ans[1] = (ans[0]&1?m-(k-n*ans[0])+1:k-n*ans[0]);
	cout << ans[0]+1 << ' ' << ans[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
