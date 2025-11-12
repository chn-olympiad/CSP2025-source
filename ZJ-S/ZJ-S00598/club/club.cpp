#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define int long long
#define N 100005
#define MAX 1145141919810
#define endl "\n"
#define TXYAKIOI 91
#define mod 78
using namespace std;
int T;
int n,a[N][4];
struct node{
	int w,choose,chnum,der;
}dp[N];
struct NODE{
	int der,id;
}Check[N];
int cnt[4];
inline bool cmp(NODE x,NODE y){
	return x.der<y.der;
}
inline void Main(){
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	rep(i,1,n)
		rep(j,1,3)
			cin>>a[i][j];
			
	rep(i,1,n){
		int sum=-1,sum1=-1,tmp;
		rep(j,1,3)if(a[i][j]>sum){sum=a[i][j];tmp=j;}
		rep(j,1,3)if(j!=tmp)sum1=max(sum1,a[i][j]);
		dp[i].w=dp[i-1].w+sum;
		dp[i].choose=sum;
		dp[i].chnum=tmp;
		dp[i].der=sum-sum1;
		++cnt[tmp];
 	}
 	rep(k,1,3)
 		if(cnt[k]>n/2){
 			int ans=0,ot=dp[n].w;
 			memset(Check,0,sizeof(Check));
 			
 			rep(i,1,n)
			 	if(dp[i].chnum==k){
			 		Check[++ans].der=dp[i].der;
			 		Check[ans].id=i;
				 }
				 
			sort(Check+1,Check+ans+1,cmp);
			int nout=cnt[k]-n/2;
			rep(xx,1,nout){
				int i=Check[xx].id,ma=-1;
				rep(l,1,3)
					if(l!=dp[i].chnum)
						ma=max(ma,a[i][l]);
				ot=ot+ma-dp[i].choose;
			}
			cout<<ot<<endl;
			return;
		}
	cout<<dp[n].w<<endl;
}
inline void Enchanted(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)Main();
}
signed main(){Enchanted();return 0;}
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
