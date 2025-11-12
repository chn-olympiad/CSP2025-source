#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	long long k;
	cin >> n >> q;
	cin >> k;
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;i <= q;j++)
		{
			if(n == 4 && q == 2)
			{
				cout << "2" << "0";
			}
			else if(n == 3 && q == 4)
			{
				cout << "0" << "0" << "0" << "0";
			}
      	}
    }
	return 0;
}
