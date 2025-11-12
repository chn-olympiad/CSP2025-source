#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
//------------------
inline int read(){
	int f = 1,x = 0;
	char c = getchar();
	while(c != '-' && !('0' <= c && c <= '9'))
		c = getchar();
	if(c == '-')
		f = -1,c = '0';
	while('0' <= c && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
//------------------
int a[N][5],b[N][5];
int T,n,tmp[5];
int solve(){
	priority_queue<int,vector<int>,greater<int> > heap;
	int ans = 0;
	int tmp[5] = {0};
	for(int i = 1;i <= n;i++){
		int tx = a[i][1],ty = a[i][2],tz = a[i][3];
		b[i][1] = 1,b[i][2] = 2,b[i][3] = 3;
		if(tx < ty){
			swap(tx,ty);
			swap(b[i][1],b[i][2]);
		}
		if(ty < tz){
			swap(ty,tz);
			swap(b[i][2],b[i][3]);
		}
		if(tx < ty){
			swap(tx,ty);
			swap(b[i][1],b[i][2]);
		}
		tmp[b[i][1]]++,ans += a[i][b[i][1]];
	}
	if(tmp[1] <= n / 2 && tmp[2] <= n / 2 && tmp[3] <= n / 2)
		return ans;
	int maxn = max(tmp[1],max(tmp[2],tmp[3]));
	int idx = (maxn == tmp[1] ? 1 : (maxn == tmp[2] ? 2 : 3));
	for(int i = 1;i <= n;i++)
		if(b[i][1] == idx)
			heap.push(a[i][b[i][1]]-a[i][b[i][2]]);
	for(int i = 0;i < maxn - n / 2;i++){
		ans -= heap.top();
		heap.pop();
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		int res = 0;
		memset(a,0,sizeof(a));
		n = read();
		for(int i = 1;i <= n;i++)
			a[i][1] = read(),a[i][2] = read(),a[i][3] = read();
		res = max(res,solve());
		printf("%d\n",res);
	}
	return 0;
}
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
