#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node{
	long long x , y , z;
	long long bk;
}a[N];	
bool cmp1(node a , node b){
	return a.x > b.x;
}
bool cmp2(node a , node b){
	return abs(a.x - a.y) < abs(b.x - b.y);
}
bool cmp3(node a , node b){
	return abs(a.x - a.z) < abs(b.x - b.z);
}
bool cmp4(node a , node b){
	return abs(a.y - a.z) < abs(b.y - b.z);
}
bool cmp(node a , node b){
	return a.bk > b.bk;
}
int n , m , s1 , s2 , vis[N];
long long f1(){
	m = n / 2;
	long long ans = 0;
	s1 = 0 , s2 = 0; 
	sort(a + 1 , a + n + 1 , cmp2);
	for(int i = m + 1; i <= n; i++){
		if(a[i].x >= a[i].y){
			s1++;
			ans += a[i].x;
			a[i].bk = a[i].z - a[i].x;
		} else {
			s2++;
			ans += a[i].y;
			a[i].bk = a[i].z - a[i].y;
		}
	}
	for(int i = m; i >= 1; i--){
		if(a[i].x >= a[i].y){
			if(s1 < m){
				ans += a[i].x;
				s1++;
				a[i].bk = a[i].z - a[i].x;
			} else {
				ans += a[i].y;
				s2++;
				a[i].bk = a[i].z - a[i].y;
			}
		} else {
			if(s2 < m){
				ans += a[i].y;
				s2++;
				a[i].bk = a[i].z - a[i].y;
			} else {
				ans += a[i].x;
				s1++;
				a[i].bk = a[i].z - a[i].x;
			}
		}
	}
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1; i <= m; i++){
		if(a[i].bk > 0){
			ans += a[i].bk;
		}
	}
	return ans;
}
long long f2(){
	m = n / 2;
	long long ans = 0;
	s1 = 0 , s2 = 0; 
	sort(a + 1 , a + n + 1 , cmp3);
	for(int i = m + 1; i <= n; i++){
		if(a[i].x >= a[i].z){
			s1++;
			ans += a[i].x;
			a[i].bk = a[i].y - a[i].x;
		} else {
			s2++;
			ans += a[i].z;
			a[i].bk = a[i].y - a[i].z;
		}
	}
	for(int i = m; i >= 1; i--){
		if(a[i].x >= a[i].z){
			if(s1 < m){
				ans += a[i].x;
				s1++;
				a[i].bk = a[i].y - a[i].x;
			} else {
				ans += a[i].z;
				s2++;
				a[i].bk = a[i].y - a[i].z;
			}
		} else {
			if(s2 < m){
				ans += a[i].z;
				s2++;
				a[i].bk = a[i].y - a[i].z;
			} else {
				ans += a[i].x;
				s1++;
				a[i].bk = a[i].y - a[i].x;
			}
		}
	}
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1; i <= m; i++){
		if(a[i].bk > 0){
			ans += a[i].bk;
		}
	}
	return ans;
}
long long f3(){
	m = n / 2;
	long long ans = 0;
	s1 = 0 , s2 = 0; 
	sort(a + 1 , a + n + 1 , cmp4);
	for(int i = m + 1; i <= n; i++){
		if(a[i].y >= a[i].z){
			s1++;
			ans += a[i].y;
			a[i].bk = a[i].x - a[i].y;
		} else {
			s2++;
			ans += a[i].z;
			a[i].bk = a[i].x - a[i].z;
		}
	}
	for(int i = m; i >= 1; i--){
		if(a[i].y >= a[i].z){
			if(s1 < m){
				ans += a[i].y;
				s1++;
				a[i].bk = a[i].x - a[i].y;
			} else {
				ans += a[i].z;
				s2++;
				a[i].bk = a[i].x - a[i].z;
			}
		} else {
			if(s2 < m){
				ans += a[i].z;
				s2++;
				a[i].bk = a[i].x - a[i].z;
			} else {
				ans += a[i].y;
				s1++;
				a[i].bk = a[i].x - a[i].y;
			}
		}
	}
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1; i <= m; i++){
		if(a[i].bk > 0){
			ans += a[i].bk;
		}
	}
	return ans;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		m = n / 2;
		long long ans = 0; 
		bool p1 = 0 , p2 = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0) p1 = 1;
			if(a[i].z != 0) p1 = 1 , p2 = 1;
		}
		if(!p1){
			sort(a + 1 , a + n + 1 , cmp1);
			for(int i = 1; i <= m; i++){
				ans += a[i].x;
			}
			cout << ans << '\n';
		} else if(!p2){
			s1 = 0 , s2 = 0;
			for(int i = 1; i <= n; i++){
				if(a[i].x > a[i].y) s1++;
				else s2++;
			}
			if(s1 <= m && s2 <= m){
				for(int i = 1; i <= n; i++){
					if(a[i].x > a[i].y){
						ans += a[i].x;
					} else ans += a[i].y;
				} 
			}  else {
				s1 = 0 , s2 = 0; 
				sort(a + 1 , a + n + 1 , cmp2);
				for(int i = m + 1; i <= n; i++){
					if(a[i].x > a[i].y){
						s1++;
						ans += a[i].x;
					} else {
						s2++;
						ans += a[i].y;
					}
				}
				for(int i = m; i >= 1; i--){
					if(a[i].x > a[i].y){
						if(s1 < m){
							ans += a[i].x;
							s1++;
						} else {
							ans += a[i].y;
							s2++;
						}
					} else {
						if(s2 < m){
							ans += a[i].y;
							s2++;
						} else {
							ans += a[i].x;
							s1++;
						}
					}
				}
			}
			cout << ans << '\n';
		} else {
			for(int i = 1; i <= n; i++){
				if(a[i].x > a[i].y){
					s1++;
				} else s2++;
			}
			if(s1 <= m && s2 <= m){
				for(int i = 1; i <= n; i++){
					if(a[i].x > a[i].y){
						ans += a[i].x;
					} else ans += a[i].y;
				} 
			} else {
				long long ans1 = f1() , ans2 = f2() , ans3 = f3();
				cout << max(ans1 , max(ans2 , ans3)) << '\n';
			}
		}
	}	
	return 0;
}