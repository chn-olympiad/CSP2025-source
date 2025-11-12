#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int MAXN=200010;
int n;
int a[MAXN][4];
ll Mans=0;

void dfs(ll fir,ll sec,ll thr,ll w){
	ll now=fir+sec+thr+1;
	if (now>n)
	{
		if (fir<=n/2 && sec<=n/2 && thr<=n/2)
			Mans=max(Mans,w);
		return;
	}
	
	if (fir<=n/2) dfs(fir+1,sec,thr,w+a[now][1]);
	if (sec<=n/2) dfs(fir,sec+1,thr,w+a[now][2]);
	if (thr<=n/2) dfs(fir,sec,thr+1,w+a[now][3]);
}	
int k[MAXN];
void solve1(){
	//在a[1]中选取一半
	int MMMans=0;
	for (int i=1; i<=n; i++)
		k[i]=a[i][1];
	sort(k+1,k+1+n);
	for (int i=n,ssr=0; i>=1 && ssr<n/2; i--){
		MMMans+=k[i];
		++ssr;
	}
	cout<<MMMans<<endl;
}

void MAIN(){
	Mans=0;
	cin>>n;
	bool b=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=3; j++)
		{
			a[i][j]=read();
			if (a[i][j]!=0 && j>1) b=0;
		}
	if (b){
		solve1();
		return;
	}
	dfs(0,0,0,0);
	cout<<Mans<<endl;
	
//	priority_queue<M_P> p;
//	p.insert(M_P(0,0,0,0,0));
//	int ans=-1;
//	while(!p.empty()){
//		M_P new_p=p.top();
//		p.pop();
//		if (new_p.now>n && new_p.pos[1]<n/2 && new_p.pos[2]<n/2 &&new_p.pos[2]<n/2){
//			ans=max(ans,new_p.w);
//		}
//		p.insert(M_P(new_p.))
//	}
	/*
	//不管效率，先写一个能交的代码
	memset(f,0,sizeof f);
	for (int i=1; i<=n; i++)//基础
		f[i]=f[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
	
	//可以dp推出最大值，可是如何才能判断每一列的最大个数都不超过3
	//需要一些值来记录这些答案
	//获取可以用优先队列？
	*/
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
// 	变量名注意不要和关键词重复
	ll T;
	T=read();
	while(T--) MAIN();



	return 0;
}
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107
*/
