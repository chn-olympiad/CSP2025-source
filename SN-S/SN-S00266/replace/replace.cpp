#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int n , m ;
	cin >> n >> m ;
	string s;
	cin >> s;
	int t[1100000000] ;
	for(int i =1 ; i<= n ; i ++)
	cin >> t[i] ;
  	long long sum ;
	for(int i = 1 ; i <= n ; i ++ ) 
	{
		sum = sum * i ;
		
		
	}
	cout << sum ;
	return 0 ;
}
