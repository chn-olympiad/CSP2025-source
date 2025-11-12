#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5+24;
int a[4][N];
int _t[N],_minurium[N],_l[N];
int cnt[5];
struct node{
	int id,_minurium;
	friend bool operator <(node x,node y ){
		return x._minurium < y._minurium;
	}
}xxx[N];

inline void Read(int &x){
	short f = 1;
	char  c = getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f = -f;
		}
		c = getchar();
	}
	x = 0;
	do{
		x = (x<<1)+(x<<3);
		x+=c-'0';
		c = getchar(); 
	}while(c<='9'&&c>='0');
	x*=f;
	return ;
} 

inline  int Calc(int x){
	if(a[1][x]>=a[2][x]&&a[1][x]>=a[3][x])return 1;
	if(a[2][x]>=a[1][x]&&a[2][x]>=a[3][x])return 2;
	return 3;
}// chose the biggest

inline  int Calc1(int x){
	if(a[1][x]<=a[2][x]&&a[1][x]<=a[3][x])return 1;
	if(a[2][x]<=a[1][x]&&a[2][x]<=a[3][x])return 2;
	return 3;
}// chose the smallest


int main(){
	ll ans = 0 ;
	int T,n,be;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Read(T);
	while(T--){
		ans = 0,be = 1;
		Read(n);
		cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1;i<=n;i++){
			Read(a[1][i]);
			Read(a[2][i]);
			Read(a[3][i]);
		}
		for(int i = 1;i<=n;i++){
			_t[i] = Calc(i);
			_l[i] = Calc1(i);
			xxx[i].id = _t[i];
			xxx[i]._minurium = a[_t[i]][i] - a[6-_t[i]-_l[i]][i];//最小减少花费 
			ans+=a[_t[i]][i];
			cnt[_t[i]]++;//假设法 
		}
		
		while(be<=3&&cnt[be]<=(n>>1))
			be++;
		
		if(be<=3){
			sort(xxx+1,xxx+1+n);
			for(int i=1,j=0;i<=n && (cnt[be]-j > (n>>1));i++ ){
				if(xxx[i].id == be ){
					j++;
					ans -=xxx[i]._minurium;
				}
			}
		}//踢人直到n/2 
		printf("%lld\n",ans);
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
0 2 0
0 1 0
0 2 0
2
4  0 0 
10 9 8
*/