// 14:50 club (100pts)
// 15:21 road (1-4 for 16pts and A 32pts = 48pts)
// 15:40 (thought) replace 
// 15:36 replace (? 50pts) finished.
// 17:16 replace unsolved.
// 17:37 employ (12pts)
// 17:53 road (48pts and 8pts = 56pts)
// 18:08 road (64pts)

#include <bits/stdc++.h>
using namespace std;
int n , q;
string s[200000 + 5][2] , t[200000 + 5][2] ;
#define ll long long
const ll b1 = 7 , b2 = 13,  b3 = 19;
const ll MOD1 = 1000000000 + 7,MOD2 = 1000000000 + 9,MOD3 = 998244353 ;
vector <ll> g1[200000 + 5],g2[200000 + 5],g3[200000 + 5];
vector <ll> h1[200000 + 5],h2[200000 + 5],h3[200000 + 5];
int ls[200000 + 5];
ll t1[200000 + 5],t2[200000 + 5],t3[200000 + 5];
ll p1[200000 + 5],p2[200000 + 5],p3[200000 + 5];
ll ib1,ib2,ib3;
ll qpow (ll x,ll y,ll p) {
	ll rr = 1,xx = x;
	while (y) {
		if (y & 1) {
			rr = rr * xx % p;
		}
		y /= 2,xx = xx * xx % p;
	}
	return rr ;
}
ll qp1 (ll y) {
	ll rr = 1,xx = b1;
	while (y) {
		if (y & 1) {
			rr =  rr * xx % MOD1 ;
		}
		y /= 2,xx = xx * xx % MOD1 ;
	}
	return rr ;
}
ll qp2 (ll y) {
	ll rr = 1,xx = b2;
	while (y) {
		if (y & 1) {
			rr =  rr * xx % MOD2 ;
		}
		y /= 2,xx = xx * xx % MOD2 ;
	}
	return rr ;
}
ll qp3 (ll y) {
	ll rr = 1,xx = b3;
	while (y) {
		if (y & 1) {
			rr =  rr * xx % MOD3 ;
		}
		y /= 2,xx = xx * xx % MOD3 ;
	}
	return rr ;
}
ll qpp1 (ll y) {
	return (((qp1 (y + 1) - 1 + MOD1 - b1) % MOD1 * ib1 % MOD1)) % MOD1;
}
ll qpp2 (ll y) {
	return (((qp2 (y + 1) - 1 + MOD2 - b2) % MOD2 * ib2 % MOD2)) % MOD2;
}
ll qpp3 (ll y) {
	return (((qp3 (y + 1) - 1 + MOD3 - b3) % MOD3 * ib3 % MOD3)) % MOD3;
}
ll rg1(int id , int lb , int rb) {return (g1[id][rb + 1] - (qp1 (rb - lb + 1) * g1[id][lb]) % MOD1 + MOD1) % MOD1 ;}
ll rg2(int id , int lb , int rb) {return (g2[id][rb + 1] - (qp2 (rb - lb + 1) * g2[id][lb]) % MOD2 + MOD2) % MOD2 ;}
ll rg3(int id , int lb , int rb) {return (g3[id][rb + 1] - (qp3 (rb - lb + 1) * g3[id][lb]) % MOD3 + MOD3) % MOD3 ;}
ll rh1(int id , int lb , int rb) {return (h1[id][rb + 1] - (qp1 (rb - lb + 1) * h1[id][lb]) % MOD1 + MOD1) % MOD1 ;}
ll rh2(int id , int lb , int rb) {return (h2[id][rb + 1] - (qp2 (rb - lb + 1) * h2[id][lb]) % MOD2 + MOD2) % MOD2 ;}
ll rh3(int id , int lb , int rb) {return (h3[id][rb + 1] - (qp3 (rb - lb + 1) * h3[id][lb]) % MOD3 + MOD3) % MOD3 ;}
ll rt1(int lb , int rb) {return (t1[rb + 1] - (qp1 (rb - lb + 1) * t1[lb]) % MOD1 + MOD1) % MOD1 ;}
ll rt2(int lb , int rb) {return (t2[rb + 1] - (qp2 (rb - lb + 1) * t2[lb]) % MOD2 + MOD2) % MOD2 ;}
ll rt3(int lb , int rb) {return (t3[rb + 1] - (qp3 (rb - lb + 1) * t3[lb]) % MOD3 + MOD3) % MOD3 ;}
ll rp1(int lb , int rb) {return (p1[rb + 1] - (qp1 (rb - lb + 1) * p1[lb]) % MOD1 + MOD1) % MOD1 ;}
ll rp2(int lb , int rb) {return (p2[rb + 1] - (qp2 (rb - lb + 1) * p2[lb]) % MOD2 + MOD2) % MOD2 ;}
ll rp3(int lb , int rb) {return (p3[rb + 1] - (qp3 (rb - lb + 1) * p3[lb]) % MOD3 + MOD3) % MOD3 ;}
int main () {
	freopen ("replace.in" , "r" , stdin) ;
	freopen ("replace.out" , "w" , stdout) ;
	cin >> n >> q;
	for (int i = 1;i <= n;i ++) {
		cin >> s[i][0] >> s[i][1] ;
	}
	for (int i = 1;i <= q;i ++) {
		cin >> t[i][0] >> t[i][1] ;
	}
	ib1 = qpow (b1 - 1 , MOD1 - 2 , MOD1) ;
	ib2 = qpow (b2 - 1 , MOD2 - 2 , MOD2) ;
	ib3 = qpow (b3 - 1 , MOD3 - 2 , MOD3) ;
	for (int i = 1;i <= n;i ++) {
		ls[i] = s[i][0].length ();
		g1[i].push_back (0) ; 
		g2[i].push_back (0) ;
		g3[i].push_back (0) ;
		for (int j = 0;j < ls[i];j ++) {
			g1[i].push_back ((g1[i][j] * b1 + (s[i][0][j] - 'a')) % MOD1);
			g2[i].push_back ((g2[i][j] * b2 + (s[i][0][j] - 'a')) % MOD2);
			g3[i].push_back ((g3[i][j] * b3 + (s[i][0][j] - 'a')) % MOD3);
		}
		h1[i].push_back (0) ; 
		h2[i].push_back (0) ;
		h3[i].push_back (0) ;
		for (int j = 0;j < ls[i];j ++) {
			h1[i].push_back ((h1[i][j] * b1 + (s[i][1][j] - 'a')) % MOD1);
			h2[i].push_back ((h2[i][j] * b2 + (s[i][1][j] - 'a')) % MOD2);
			h3[i].push_back ((h3[i][j] * b3 + (s[i][1][j] - 'a')) % MOD3);
		}
	}
	if (q <= 1 || n <= 1000) {
		for (int i = 1;i <= q;i ++) {
	//		cout << "q = " << i << "\n" ;
			int len1 = t[i][0].length () , len2 = t[i][1].length ();
			ll ansss = 0;
			if (len1 != len2) {
				cout << 0 << "\n" ;
			}
			else {
				t1[0] = 0; 
				t2[0] = 0;
				t3[0] = 0;
				for (int j = 0;j < ls[i];j ++) {
					t1[j + 1] = ((t1[j] * b1 + (t[i][0][j] - 'a')) % MOD1);
					t2[j + 1] = ((t2[j] * b2 + (t[i][0][j] - 'a')) % MOD2);
					t3[j + 1] = ((t3[j] * b3 + (t[i][0][j] - 'a')) % MOD3);
				}
				p1[0] = 0; 
				p2[0] = 0;
				p3[0] = 0;
				for (int j = 0;j < ls[i];j ++) {
					p1[j + 1] = ((p1[j] * b1 + (t[i][1][j] - 'a')) % MOD1);
					p2[j + 1] = ((p2[j] * b2 + (t[i][1][j] - 'a')) % MOD2);
					p3[j + 1] = ((p3[j] * b3 + (t[i][1][j] - 'a')) % MOD3);
				}
				int tmin = len1 + 1,tmax = -1;
				for (int j = 0;j < len1;j ++) {
					if (t[i][0][j] != t[i][1][j]) {
						tmin = min (tmin , j);
						tmax = max (tmax , j);
					}
				}
				ll at1 = rt1 (tmin , tmax) , at2 = rt2 (tmin , tmax) , at3 = rt3 (tmin , tmax) ;
				ll bt1 = rp1 (tmin , tmax) , bt2 = rp2 (tmin , tmax) , bt3 = rp3 (tmin , tmax) ;
				ll tt = tmax - tmin + 1;
		//		cout<<tmin<<","<<tmax<<"\n";
				for (int j = 1;j <= n;j ++) {
					if (ls[j] < tt) {
						continue ;
					}
					for (int i1 = 0;i1 + tt - 1 < ls[j];i1 ++) {
						ll s11 = rg1 (j , i1 , i1 + tt - 1) , s12 = rg2 (j , i1 , i1 + tt - 1) ;
						ll s13 = rg3 (j , i1 , i1 + tt - 1) ;
						if (s11 == at1 && s12 == at2 && s13 == at3) {
				//			cout << "S-string " << j << " checked from " << i1 << " to " << i1 + tt - 1 << "\n" ;
							int z1 = tmin - i1 , z2 = tmax + ls[j] - 1 - (i1 + tt - 1) ;
							if (z1 < 0 || z2 >= len1) {
								continue ;
							}
							s11 = rg1 (j , 0 , ls[j] - 1) , s12 = rg2 (j , 0 , ls[j] - 1) ;
							s13 = rg3 (j , 0 , ls[j] - 1) ;
							at1 = rt1 (z1 , z2) , at2 = rt2 (z1 , z2) , at3 = rt3 (z1 , z2) ;
							if (at1 != s11 || at2 != s12 || at3 != s13) {
								continue ;
							}
							s11 = rh1 (j , 0 , ls[j] - 1) , s12 = rh2 (j , 0 , ls[j] - 1) ;
							s13 = rh3 (j , 0 , ls[j] - 1) ;
							at1 = rp1 (z1 , z2) , at2 = rp2 (z1 , z2) , at3 = rp3 (z1 , z2) ;
							if (at1 != s11 || at2 != s12 || at3 != s13) {
								continue ;
							}
							else {
								ansss ++ ;
								break ;
							}
						}
					}
				}
				cout << ansss << "\n" ;
			}
		}
	}
	return 0;
}