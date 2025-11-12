#include <bits/stdc++.h>
using namespace std ;
int x = 0, y = 0, z = 0, n = 0 ;
struct club {
	int a ;
	int b ;
	int c ;
	int ab ;
	int ac ;
	int bc ;
	int cho ;
} ;

bool cmp1(club x1, club y1) {
	if (x1.cho == 1){
		if (y + 1 > n / 2) {
			cout << x1.ac<< "  " << y1.ac << "  " ;
			return x1.ac < y1.ac ;
		}
		if (z + 1 > n / 2) {
			return x1.ab < y1.ab ;
		}
		if (x1.ab < x1.ac) {
			return x1.ab < min(y1.ab, y1.ac) ;
		}
		return x1.ac < min(y1.ab, y1.ac) ;
	}
	return false ;
}
bool cmp2(club x1, club y1) {
	if (x1.cho == 2) {
		if (x + 1 > n / 2) {
			return x1.bc < y1.bc ;
		}
		if (z + 1 > n / 2) {
			return x1.ab * -1 < y1.ab * -1 ;
		}
		if (x1.ab * -1 < x1.bc) {
			return x1.ab * -1 < min(y1.ab * -1, y1.bc) ;
		}
		return x1.bc < min(y1.ab * -1, y1.bc) ;
	}
	return false ;
}
bool cmp3(club x1, club y1) {
	if (x1.cho == 3) {
		if(x + 1 > n / 2) {
			return x1.bc > y1.bc ;
		}
		if (y + 1 > n / 2) {
			return x1.ac > y1.ac ;
		}
		if (x1.ac > x1.bc) {
			return x1.ac > max(y1.ac, y1.bc) ;
		}
		return x1.bc > max(y1.ac, y1.bc) ;
	}
	return false ;
}
int main(){
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	int t ;
	cin >> t ;
	for (int p = 0 ; p < t ; p ++) {
		n = 0 ;
		x = 0 ;
		y = 0 ;
		z = 0 ;
		club m[10000] ;
		int num = 0 ;
		cin >> n ;
		for (int i = 0 ; i < n ; i ++) {
			cin >> m[i].a >> m[i].b >> m[i].c ;
			m[i].ab = m[i].a - m[i].b ;
			m[i].ac = m[i].a - m[i].c ;
			m[i].bc = m[i].b - m[i].c ;
		}
		for (int i = 0 ; i < n ; i ++) {
			if (m[i].ab > 0 && m[i].ac > 0) {
				x += 1 ;
				m[i].cho = 1 ;
			}
			else if (m[i].bc > 0 && m[i].ab < 0) {
				y += 1 ;
				m[i].cho = 2 ;
			}
			else {
				z += 1 ;
				m[i].cho = 3 ;
			}
		}
		while (true) {
			if (x > n / 2) {
				sort(m, m + n, cmp1) ;
				x -= 1 ;
				if (y + 1 > n / 2) {
					if (m[0].ac < m[1].ac) {
						m[1].cho = 3 ;
						z += 1 ;
					}
					else {
						m[0].cho = 3;
						z += 1 ;
					}
				}
				else if (z + 1 > n / 2) {
					if (m[0].ab > m[1].ab) {
						m[0].cho = 2 ;
						y += 1 ;
					}
					else {
						m[1].cho = 2 ;
						y += 1 ;
					}
				}
				else if (m[0].ab < m[0].ac) {
					m[0].cho = 2 ;
					y += 1 ;
				}
				else {
					m[0].cho = 3 ;
					z += 1 ;
				}
			}
			else if (y > n / 2) {
				sort(m, m + n, cmp2) ;
				y -= 1 ;
				if (x + 1 > n / 2) {
					if (m[0].bc > m[1].bc) {
						m[1].cho = 3 ;
						z += 1 ;
					}
					else {
						m[0].cho = 3 ;
						z += 1 ;
					}
				}
				else if (z + 1 > n / 2) {
					if (m[0].ab < m[1].ab) {
						m[1].cho = 1 ;
						x += 1 ;
					}
					else {
						m[0].cho = 1 ;
						x += 1 ;
					}
				}
				else if (m[0].ab * -1 < m[0].bc) {
					m[0].cho = 1 ;
					x += 1 ;
				}
				else {
					m[0].cho = 3 ;
					z += 1 ;
				}
			}
			else if(z > n / 2) {
				sort(m, m + n, cmp3) ;
				z -= 1 ;
				if (x + 1 > n / 2) {
					if (m[0].bc > m[1].bc) {
						m[0].cho = 2 ;
						y += 1 ;
					}
					else {
						m[1].cho = 2 ;
						y += 1 ;
					}
				}
				else if (y + 1 > n / 2) {
					if (m[0].ac > m[1].ac) {
						m[0].cho = 1 ;
						x += 1 ;
					}
					else {
						m[1].cho = 1 ;
						x += 1 ;
					}
				}
				else if (m[0].ac > m[0].bc) {
					m[0].cho = 1 ;
					x += 1 ;
				}
				else {
					m[0].cho = 2 ;
					y += 1 ;
				}
			}
			else {
				break ;
			}
	}
	for (int i = 0 ; i < n ; i ++) {
		if (m[i].cho == 1) {
			num += m[i].a ;
		}
		else if (m[i].cho == 2) {
			num += m[i].b ;
		}
		else {
			num += m[i].c ;
		}
	}
	cout << num << endl ;
	}
	
	return 0 ;
}
