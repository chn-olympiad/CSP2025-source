#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define endl "\n"
#define N -114514
#define int long long
#define MAX 1145141919810
#define TXYAKIOI 91
using namespace std;
int n,m,sc,X,Y;
int up,non;
int in[205];
int a[15][15];
inline bool cmp(int x,int y){return x>y;}
inline void Enchanted(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	X=Y=1;up=1;
	rep(i,1,n*m)cin>>in[i];
	non=in[1];
	sort(in+1,in+n*m+1,cmp);
	rep(i,1,n*m){
		a[Y][X]=in[i];
		if(Y==n&&X%2==1){
			up=-1;
			++X;
		}
		else if(Y==1&&X%2==0){
			up=1;
			++X;
		}
		else Y+=up;
	}
	rep(i,1,n)
		rep(j,1,m)
			if(a[j][i]==non)
				cout<<i<<' '<<j;
//	rep(i,1,n){
//		rep(j,1,m)
//			cout<<a[i][j]<<' ';
//		cout<<endl;
//	}
}
signed main(){Enchanted();return 0;}

