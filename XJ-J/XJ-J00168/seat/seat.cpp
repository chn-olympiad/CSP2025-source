#include<bits/stdc++.h>
using namespace std;

long long int n,m,mark[105],i,R;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(i = 0;i < n*m;i++) cin >> mark[i];
	R = mark[0];
	sort(mark,mark+n*m-1,greater<long long int>());
	for(i = 0;i < n*m;i++)
	{
		if(mark[i] == R)
		{
			if((i+1) % n == 0)
			{
				cout << (i+1)/n << " ";
				if(((i+1)/n) % 2 == 0) cout << 1;
				else cout << n;
			}
			else
			{
				cout << (i+1)/n+1 << " ";
				if(((i+1)/n+1) % 2 == 0) cout << n-((i+1)%n)+1;
				else cout << (i+1)%n;
			}
			
		}
	}
	return 0;
}
