#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
using namespace std;
inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int T, n;
const int N = 1e5 + 10;
ll ans;
int c1, c2, c3;
int minn[N], maxn;
struct node{
	int a, b, c;
	int ida, idb, idc;
}q[N];
bool f[N];
bool cmp1(node x, node y){
	if(x.a == y.a ) return x.ida > y.ida;
	return x.a > y.a;
}
bool cmp2(node x, node y){
	if(x.b == y.b )return x.idb > y.idb; 
	return x.b > y.b;
}
bool cmp3(node x, node y){
	if(x.c == y.c )return x.idc > y.idc; 
	return x.c > y.c;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	T = read();
	while(T -- ){
		memset(minn, -1, sizeof minn);
		ans = 0;
		c1 = c2 = c3 = 0;
		n = read();
		int mm = n / 2;
		for(int i = 1; i <= n; i ++ ){
			q[i].a = read(), q[i].b = read(), q[i].c = read();
			q[i].ida = q[i].idb = q[i].idc = i;
			minn[i] = min(min(q[i].a, q[i].b), min(q[i].b, q[i].c));
			q[i].a -= minn[i], q[i]. b-= minn[i], q[i].c -= minn[i];
		}
		sort(q + 1, q + n + 1, cmp1);
		sort(q + 1, q + n + 1, cmp2);
		sort(q + 1, q + n + 1, cmp3);
		/*for(int i = 0; i < n; i ++ )
		cout << q[i].ida << " ";
		printf("%d\n");*/
		int j = 1;
		while(j <= n){
			int t = max(max(q[j].a, q[j].b), max(q[j].b, q[j].c));
			//cout << t << endl;
			if(t == q[j].a){
				int w = q[j].ida;
				if(++c1 <= mm){
				ans += t + minn[w];
				//c1 ++;
				j ++;
				}
				else if(q[w].b > q[w].c){
					c2++;
					j++;
					ans += q[w].b + minn[w];
				}
				else{
				c3++;
				j++;
				ans += q[w].c + minn[w];
				}
			}
			else if(t == q[j].b){
				int w = q[j].idb;
				if(++c2 <= mm){
				//c2 ++;
				j ++;
				ans += t + minn[w];
					
					
				}
					else if(q[w].a > q[w].c){
					c1++;
					j++;
					ans += q[w].a + minn[w];
				}
				else{
				c3++;
				j++;
				ans += q[w].c + minn[w];
				}
			}
			else if(t == q[j].c){
					int w = q[j].idc;
				if(++c3 <= mm){
					//c3 ++;
					j ++;
					ans += t + minn[w];
				}
					else if(q[w].a > q[w].b){
					c1++;
					j++;
					ans += q[w].a + minn[w];
				}
				else{
				c2++;
				j++;
				ans += q[w].b + minn[w];
				}
			}	
	t = 0;
	}
	printf("%d\n", ans);
}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
