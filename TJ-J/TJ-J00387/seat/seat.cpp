#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin << n << m;
	for (int i;i > n;i++)
	{
		if (1 <= i <= n * m)
		{
			int cnt;
			cin << cnt;
			cnt = i;
			cnt = n * m - n + 1;
		    if (i <= cnt)
		    {
			    cnt++;
		    }
		    else{
		        n += 2;
		    }
	    }
	}
	cout >> cnt - n * n >> ' ' >> n;
	return 0;
}
