#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 10 ;
int n , q ;
string s1[N] , s2[N] ;
int main()
{
	freopen("replace.in" , "r" , stdin) ;
	freopen("replace.out", "w" , stdout) ;
	cin >> n >> q ;
	for(int i = 1 ; i <= n ; i ++) cin >> s1[i] >> s2[i] ;
	//cout << s1[1].substr(0 , 0 + 1) ;
	if(n * q <= 1000000)
	{
		for(int i = 1 ; i <= q ; i ++)
		{
			string t1 , t2 , t3 ;
			cin >> t1 >> t2 ;
			int cnt = 0 ;
			
			int len = t1.size() ;
			for(int j = 1 ; j <= n ; j ++)
			{
				int ll = s1[j].size() ;
				//cout << ll ;
				
				for(int k = 0 ; k + ll <= t1.size() ; k ++)
				{
					t3 = t1.substr(k , len) ;
					int l = t3.find(s1[j]) ;
						
//					if(l != -1) 
//					{
//						if(l + s2[i].size() < len)
//					//cout << t3.substr(l + s2[i].size(), len) << endl;
//						//string t4 = t1.substr(0 , k) + t3.substr(k , l) + s2[i] + t3.substr(l + s2[i].size(), len);
//					//	cout << t4 ;
//						//if(t4 == t2) cnt ++ ;
//					}
				}
				
			}
			cout << cnt << endl;
	 	} 
	}
	return 0 ;
}