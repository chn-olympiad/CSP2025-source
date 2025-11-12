#include<bits/stdc++.h>
using namespace std ;

int t , n ;
int tes[5] ;
int blg[5] ;
int w[6] ;
int kk=0 ;

int main()
{
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin >> t ;
	for (int j = 0 ; j < t ; j ++ )
	{
		cin >> n ;
		if (n = 2) 
		{
			cin >> tes[1] >> tes[2] >> tes[3] ;
			cin >> blg[1] >> blg[2] >> blg[3] ;
			w[0] = tes[1] + blg[2] ;
			w[1] = tes[1] + blg[3] ;
			w[2] = tes[2] + blg[1] ;
			w[3] = tes[2] + blg[3] ;
			w[4] = tes[3] + blg[1] ;
			w[5] = tes[3] + blg[2] ;
			for (int i = 0 ; i < 6 ; i ++ )
			{
				if (kk < w[i] ) kk = w[i] ;
			}
			cout << kk << endl ;
		}
	}
	
	return 0 ;
}
