#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c ^ 48),c = getchar();
	return x * f;
}
const int M = 5,N = 100005;
int T,n,a[N][M],w[N],g[N];
int b[N],m;
int f[M];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		for(int i = 1;i <= n;i++)
			for(int j = 0;j < 3;j++)	a[i][j] = read();
		f[0] = f[1] = f[2] = 0;
		for(int i = 1;i <= n;i++){
			w[i] = max({a[i][0],a[i][1],a[i][2]});
			for(int j = 0;j < 3;j++)
				if(a[i][j] == w[i]){
					f[j]++,g[i] = j;
					break;
				}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++)	ans += w[i];
//		printf("f = %d,%d,%d\n",f[0],f[1],f[2]);
		if(max({f[0],f[1],f[2]}) <= n / 2){
			printf("%d\n",ans);
			continue;
		}
		int x = max({f[0],f[1],f[2]}),id;
		if(f[0] == x)	id = 0;
		if(f[1] == x)	id = 1;
		if(f[2] == x)	id = 2;
		m = 0;
		for(int i = 1;i <= n;i++){
			if(g[i] == id){
				int y = 0;
				for(int j = 0;j < 3;j++)
					if(j != g[i])	y = max(y,a[i][j]);
				b[++m] = w[i] - y;
//				printf("%d:%d\n",i,w[i] - y);
			}
		}
		sort(b+1,b+1+m);
		for(int i = 1;i <= x - n / 2;i++)	ans -= b[i];
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

ans:4
*/