#include <iostream>
#include <cstdio>
using namespace std ; 

int main()
{
	freopen("club.in" , "r",stdin) ; 
	freopen("club.out" ,"W",stdout) ; 
	
	int n,t,cnt1 = 0,cnt2 = 0,cnt3 = 0,a[1000] = {} ; 
	cin >> n  ; 
	for (int i = 1 ; i <= t ; i++) 
	{
		cin >> a[i] ; 
		for(int j = 0 ; j <= 2 ; j++)
		{
			cin >> a[i][j] ; 
			if(a[i][0] > a[i][1] > a[i][2])
			{
				cnt1 += a[i][0] ; 
			}
			else if(a[i][1] > a[i][0] > a[i][2])
			{
				cnt2 += a[i][1] ; 
			}
			else if(a[i][2] > a[i][0] > a[i][2]) 
			{
				cnt3 += a[i][2] ; 
			}
		}
	}
	cout << cnt1 << endl << cnt2 << endl << cnt3 ; 
	
	return 0 ; 
}
