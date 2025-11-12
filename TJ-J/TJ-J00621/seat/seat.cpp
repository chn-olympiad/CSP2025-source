#include <bits/stdc++.h>
using namespace std;
int n[105],m[105],a[105];
int main()
{ 
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i]
		if(a[i]<a[i+1])
		{
			m++;
			if(i>=m)
			{
				m[i]=1;
				n++;
			}
		}
	}
	cout<<n<<m; 
	return 0;
}
