#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+2;
int a[maxn],b[maxn],c[maxn];
int n,t,zf;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	for(int i = 1;i <= n;i++)
    	{
    		cin >> a[i] >> b[i] >> c[i];
    		if(a[i] >= b[i] && a[i] >= c[i])
    		{
    			zf += a[i];
			} 
		}
	    cout << zf;
	}
	return 0;
}
