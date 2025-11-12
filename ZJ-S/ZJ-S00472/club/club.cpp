#include<bits/stdc++.h>
using namespace std;

#define gc getchar()

inline void read(int &x){
	x=0;
	int p=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	x*=p;
}
#undef gc

const int N=1e5+10;
//int a[N],b[N],c[N];
int sz[4],ans,n,fa[N];
struct node{
	int u,v,w,dt;
}e[N*3];

inline bool cmp(node x,node y){
	return x.dt>y.dt;
}

struct noi{
	int a,b,c;
}a[N];

int ss[N];

void solveA(){
	for(int i=1;i<=n;i++){
//		a[i].a=ss[i];
		ss[i]=a[i].a;
	}
	int ans=0;
	sort(ss+1,ss+1+n);
	for(int i=n;i>n/2;i--){
		ans+=ss[i];
	}
	cout<<ans<<endl;
}

int s[N];

int dp[N];

void solveB(){
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		s[i]=a[i].a;
		ss[i]=a[i].b;
	}
	dp[1]=s[1],dp[0]=ss[1];
	for(int i=2;i<=n;i++){
		for(int j=min(n/2-1,i-1);j>=0;j--){
			dp[j+1]=max(dp[j+1]+ss[i],dp[j]+s[i]);
		}
		dp[0]+=ss[i];
//		for(int j=0;j<=min(n/2,i);j++)dp[j]+=ss[i];
	}
	cout<<dp[n/2]<<endl;
}

signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		read(n);
		int spa=0,spb=0;
		for(int i=1;i<=n;i++){
			read(a[i].a);
			read(a[i].b);
			read(a[i].c);
			if(a[i].b==0 and a[i].c==0)spa++;
			if(a[i].c==0)spb++;
		}
		if(spa==n){
			solveA();
		}else{
			if(spb==n){
				solveB();
			}
		}
	}
	
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

1
4
10 9 0
4 0 0
13 2 0
22 19 0
*/
