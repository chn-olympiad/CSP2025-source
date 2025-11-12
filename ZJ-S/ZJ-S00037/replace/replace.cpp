#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

ull Hash(string s)
{
	ull ans = 0 ;
	
	for(ull i = 0 ; s[i] ; i ++)
	{
		ans = ans * 998244353 + (s[i] - '0') ;
	}		
	
	return ans ;
}

map<pair<ull, ull>, bool> mp ;

int main()
{
	freopen("replace.in", "r", stdin) ;
	freopen("replace.out", "w", stdout) ;
	
	ull n, q ;
	cin >> n >> q ;
	
	for(ull i = 1 ; i <= n ; i ++)
	{
		string s1, s2 ;
		cin >> s1 >> s2 ;
		
		ull t1 = Hash(s1), t2 = Hash(s2) ;
		
//		pair<ull, ull> p ;
//		p.first = t1 ; p.first = t2 ;
	
//		cout << t1 << ' ' << t2 << '\n' ;
		
		mp[{t1, t2}] = true ;
 	}
	
//	cout << "\n\n\n" ;
	
	for(ull i = 1 ; i <= q ; i ++)
	{
		string s1, s2 ;
		cin >> s1 >> s2 ;
		
		ull n = s1.size(), m = s2.size() ;
		
		if(n != m)
		{
			cout << 0 << '\n' ;
			continue ;
		}
		
		ull ans = 0, state = 0 ;
		
	    ull l = 0, r = 0 ;
		
		string res1, res2 ;
		string tmp1, tmp2 ;
		
		for(ull i = 1 ; i <= n ; i ++)
		{
			if(s1[i - 1] == s2[i - 1])
			{
				if(tmp1 != "" && tmp2 != "")
				{
					state ++ ;
					r = i - 1 ;
					res1 = tmp1 ; res2 = tmp2 ;
					tmp1 = tmp2 = "" ;
				}
			}
			else
			{
				l = i - 1 ;
				
				tmp1 += s1[i - 1] ;
				tmp2 += s2[i - 1] ;
			}
		}
		
//		cout << res1 << ' ' << res2 << '\n' ;
		
		if(tmp1 != "" && tmp2 != "")
		{
			state ++ ;
			r = i - 1 ;
			res1 = tmp1 ; res2 = tmp2 ;
			tmp1 = tmp2 = "" ;
		}
		
		if(state > 1)
		{
			cout << 0 << '\n' ;
			continue ;
		}
		
//		cout << l << ' ' << r << '\n' ;
		
		for(ull i = l ; i >= 1 ; i --)
		{
			if(i != l)
			{
				res1 = s1[i - 1] + res1 ;
			    res2 = s2[i - 1] + res2 ;
			}
			
			string tmp1 = res1 ;
			string tmp2 = res2 ;
			
			for(ull j = r ; j <= n ; j ++)
			{		
			    if(j != r)
				{
					tmp1 += s1[j - 1] ;
				    tmp2 += s2[j - 1] ;
				}		
				
//				cout << tmp1 << ' ' << tmp2 << '\n' ;
				
				ull t1 = Hash(tmp1), t2 = Hash(tmp2) ;
		        
		        if(mp[{t1, t2}])
		        {
		        	ans ++ ;
				}
			}
		}
		
		cout << ans << '\n' ;
	}
		
	return 0 ;
}
