#include <bits/stdc++.h>
#define LL int 
using namespace std;

inline LL read(){
	LL x = 0,f = 1;
	char c = getchar();
	while(c > '9'|| c < '0'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' &&c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * f;
}

const int N = 1e5 + 10;

LL n, m;
struct Node {
	int v, op;
};

map<int, int> vis1, vis2, vis3;
Node f[N], s[N], th[N];

inline bool cmp(Node a, Node b){
	return a.v > b.v;
}

int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read();
	while(t -- ){
		n = read();
		int now1 = n / 2, now2 = n / 2, now3 = n / 2, sum = 0;
		for(int i = 1;i <= n;i ++ ) f[i].v = read(), s[i].v = read(), th[i].v = read();
		for(int i = 1;i <= n;i ++ ) f[i].op = i, s[i].op = i, th[i].op = i;
		sort(f + 1, f + n + 1, cmp);
		sort(s + 1, s + n + 1, cmp);
		sort(th + 1, th + n + 1, cmp);
		for(int i = 1;i <= now1;i ++ ) sum += f[i].v, vis1[f[i].op] = 1;
		for(int i = 1;i <= now2;i ++ ){
			if(!vis1[s[i].op]) vis2[s[i].op] = 1, sum += s[i].v;
			else {
				now1 ++ ;
				while(now1 <= n && vis2[f[now1].op])now1 ++;
					if(f[now1].v + s[i].v > f[i].v){
						sum = sum + f[now1].v + s[i].v - f[i].v;
						vis2[s[i].op] = 1, vis1[f[now1].op] = 1;
					}
					else now2 ++ ;
				}
			}
//		for(int i = 1;i <= )
		printf("%d\n", sum);
	}
	return 0;	
}
/*
抽象 Ren5Jie4Di4Ling5%
看看今年CCF整什么活 

tmd差点被第一题整治了 
woc真被整治了，贪错了 

*/
