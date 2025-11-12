#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;

struct _person{
	int pid, t, maxn;
	int a, b, c;
}person[N], A[N], B[N], C[N];
long long aq, bq, cq;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' or ch < '0'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch <= '9' and ch >= '0'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int n){
	if(n < 0){
		putchar('-');
		n *= -1;
	}
	if(n > 9){
		write(n / 10);
	}
	putchar(n % 10 + '0');
}

//void solve(int x){
//	if(x == 3){
//		if()
//	}
//}

bool cmpa(_person a, _person b){return a.a != b.a ? a.a > b.a : a.pid < b.pid;} 
bool cmpb(_person a, _person b){return a.b != b.b ? a.b > b.b : a.pid < b.pid;} 
bool cmpc(_person a, _person b){return a.c != b.c ? a.c > b.c : a.pid < b.pid;} 

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T --){
		bool b = 0;
		int n, n2;
		cin >> n;
		n2 = n >> 1;
		for(int i = 0; i < n; i ++){
			person[i].a = read(), person[i].b = read(), person[i].c = read();
			person[i].pid = i;
			person[i].maxn = max(max(person[i].a, person[i].b), max(person[i].b, person[i].c));
			if(person[i].a == person[i].maxn)	person[i].t += 1;
			if(person[i].b == person[i].maxn)	person[i].t += 2;
			if(person[i].c == person[i].maxn)	person[i].t += 4;
			if(person[i].c != 0 or person[i].b != 0){
				b = 1;
			}
			
		}
		if(!b){
			sort(person, person + n, cmpa);
			for(int i = 0; i < n / 2; i ++){
				aq += person[i].a;
			}
		}
		cout << aq << endl;
	}
	return 0;
} 