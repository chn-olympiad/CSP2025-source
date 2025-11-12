#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n, m, c=1, r=0;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
    {
   	    for(int j = 0;i < m; j++)
   	    {
		   cin >> a[i][j];
		}
    }
    for(int i = 0; i < n; i++)
    {
   	    for(int j = 0;i < m; j++)
   	    {
		    if(a[i][j]>a[i][j+1]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i+1][j+1])
		    {
		    	r++;
				cout << c << " " << r;
			}
		}
    }
    return 0;
}
