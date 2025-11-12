#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
	return s;
}
const int N = 1e5+5;
int T,n,a[N][3],ct[3],mi[N],dv[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		assert(!(n&1));
		ct[0] = ct[1] = ct[2] = 0;
		int mans = 0;
		for(int i = 1;i<=n;i++){
			mi[i] = 0;
			for(int o:{0,1,2}){
				a[i][o] = read();
				if(a[i][o]>a[i][mi[i]])mi[i] = o;
			}
			mans+=a[i][mi[i]];
			ct[mi[i]]++;
		}
		int am = 0;
		for(int o:{0,1,2})
			if(ct[o]>ct[am])am = o;
		if(ct[am]<=n/2){
			printf("%d\n",mans);
			continue;
		}
		int dc = 0;
		for(int i = 1;i<=n;i++){
			if(mi[i]!=am)continue;
			dv[++dc] = 0;
			for(int o:{0,1,2})
				if(o!=mi[i])dv[dc] = max(dv[dc],a[i][o]);
			dv[dc] = a[i][mi[i]]-dv[dc];
		}
		sort(dv+1,dv+dc+1);
		dc-=n/2;
		for(int i = 1;i<=dc;i++)mans-=dv[i];
		printf("%d\n",mans);
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
