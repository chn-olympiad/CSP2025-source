#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500,M=1e5+100;
int dp[N][N][N],dps[N][N],n,ans=0;
struct node{
	int a,b,c;
}st[M];
bool f1=1,f2=1;
void memst(){
	if(!f1){
		for(int i=0;i<n+10;i++){
			for(int j=0;j<n+10;j++){
				if(!f2){
					for(int k=0;k<n+10;k++){
						dp[i][j][k]=0;
					}
				}
				else if(f2) dps[i][j]=0;
			}
		}
	}
	f1=1,f2=1;
}
bool cmp(node a,node b){
	if(a.b!=b.b) return a.b>b.b;
	else if(a.a!=b.a) return a.a>b.a;
	else return a.c>b.c;
}
ll solve1(){
	ll res=0;
	for(int i=n;n-i<ceil(n/2.0);i--){
		res+=st[i].a;
	}
	return res;
}
ll solve2(){
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(i==0&&j==0) continue;
			dps[i][j]=max((i!=0?dps[i-1][j]+st[i+j].b:0),(j!=0?dps[i][j-1]+st[i+j].a:0));
		}
	}
	ll mx=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			mx=max(mx,(ll)dps[i][j]);
		}
	}
	return mx;
}
ll solve3(){
	ll mx=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i==0&&j==0&&k==0) continue;
				dp[i][j][k]=max(max(\
				(i!=0?dp[i-1][j][k]+st[i+j+k].b:0),\
				(j!=0?dp[i][j-1][k]+st[i+j+k].a:0)),\
				(k!=0?dp[i][j][k-1]+st[i+j+k].c:0));
				mx=max(mx,(ll)dp[i][j][k]);
			}
		}
	}
	return mx;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> st[i].a >> st[i].b >> st[i].c;
			if(st[i].b!=0||st[i].c!=0) f1=0;
			if(st[i].c!=0) f2=0,f1=0;
		}
		sort(st+1,st+1+n,cmp);
		if(f1){
			cout << solve1();
		}else if(f2){
			cout << solve2();
		}else{
			cout << solve3();
		}
		cout << endl;
		memst();
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
