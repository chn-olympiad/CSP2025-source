#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

int n;

int A[N] , B[N] , C[N];
bool st[N];

void bl1();
void bl2();

void slove() {
	bool Bbl2 = true;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i ++) {
		scanf("%d%d%d" , &A[i] , &B[i] , &C[i]);
		if(B[i] || C[i]) Bbl2 = false;
	}
	
	if(n <= 200) {
		bl1();
		return;
	}
	
	if(Bbl2) {
		bl2();
		return;
	}
	
	unordered_map<int,int> ai , bi , ci;
	for(int i = 1 ; i <= n ; i ++)
		ai[A[i]] = i , bi[B[i]] = i , ci[C[i]] = i;
	sort(A+1 , A+n+1);
	sort(B+1 , B+n+1);
	sort(C+1 , C+n+1);
	int al = n , bl = n , cl = n;
	int ar = 0 , br = 0;
	LL res = 0;
	memset(st , 0 , sizeof st);
	for(int i = 1 ; i <= n ; i ++ ) {
		while(al >= 1 && st[ai[A[al]]]) al --;
		while(bl >= 1 && st[bi[B[bl]]]) bl --;
		while(cl >= 1 && st[ci[C[cl]]]) cl --; 
		
		if(A[al] >= B[bl] && A[al] >= C[cl] && ar < n/2) {
			res += A[al]; st[ai[A[al]]] = true; ar ++;
		} else if(B[bl] >= A[al] && B[bl] >= C[cl] && br < n/2) {
			res += B[bl]; st[bi[B[bl]]] = true; br ++; 
		} else {
			res += C[cl]; st[ci[C[cl]]] = true;
		}
	} 
	printf("%lld\n" , res);
}

int fbl1[2][110][110];

void bl1() {
	// 55pts
	memset(fbl1 , 0 , sizeof fbl1);
	int m = n/2;
	
	int res = 0;
	for(int i = 1 ; i <= n ; i ++) {
		for(int a = 0 ; a <= m ; a ++) {
			if(a > i) break;
			for(int b = 0 ; b <= m ; b ++) {
				int c = i-a-b;
				if(c > m) continue;
				
				int& t = fbl1[i&1][a][b];
				if(a)
					t = max(t , fbl1[(i&1)^1][a-1][b]+A[i]);
				if(b)
					t = max(t , fbl1[(i&1)^1][a][b-1]+B[i]);
				if(c)
					t = max(t , fbl1[(i&1)^1][a][b]+C[i]);
				
				if(i == n)
					res = max(res , fbl1[i&1][a][b]);
			}
		}
		
		for(int a = 0 ; a <= m ; a ++) {
			for(int b = 0 ; b <= m ; b ++) {
				if(i-a-b>m) continue;
				fbl1[(i&1)^1][a][b] = 0;
			}
		}
	}
	printf("%d\n" , res);
	return;
}

void bl2() {
	// 5pts
	sort(A+1 , A+n+1);
	LL res = 0;
	for(int i = n ; i >= n/2 ; i --)
		res += A[i];
	printf("%lld\n" , res); 
}

int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int T; scanf("%d" , &T);
	while(T --) slove();
	return 0;
}

