#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n,m,k=1;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
    	cin >> a[i];
	}
    for(int i=2;i<=n*m;i++)
    {
    	if(a[i]>a[1])
    	{
    		k++;
		}
	}
	if(k%n!=0)
	{
		cout << k/n+1 << " ";
		if((k/n+1)%2==0)
		{
			cout << n+1-k%n;
		}
		else{
			cout << k%n;
		}
	}
	else{
		cout << k/n << " ";
		if((k/n)%2==0)
		{
			cout << 1;
		}
		else{
			cout << n;
		}
	}
	return 0;
}

