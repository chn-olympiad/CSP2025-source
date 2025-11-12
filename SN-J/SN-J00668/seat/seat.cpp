incloud <stdc++.h>
using namespace.std;
int main()
{
	freopen('seat.in','r',stdin);
	freopen('seat.out','w',stdout);
	long long n,m,k;
	cin >> n >> m;
	k = n*m;
	for (i=0,i<=k,i++)
	{
		if(k[i]<=k[i+1])
		{
			k[i+1] = k[i];
		}
	}
	cout << n*m;	
	
	return 0;
}
