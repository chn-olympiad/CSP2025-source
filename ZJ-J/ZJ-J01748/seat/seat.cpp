#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
constexpr int N=10+10;using namespace std;
int n,m,A[N*N],mp[N][N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	forUp(i,1,n*m)cin>>A[i];
	int val=A[1],tot=0;
	forUp(j,1,m){
		if(j%2==1)forUp(i,1,n)mp[i][j]=++tot;
		else forDown(i,n,1)mp[i][j]=++tot;
	}
	sort(A+1,A+n*m+1,greater<int>());
	int rk=0;
	forUp(i,1,n*m)if(A[i]==val){rk=i;break;}
	forUp(i,1,n)forUp(j,1,m){
		if(mp[i][j]==rk){
			cout<<j<<' '<<i;
			return 0;
		}
	}
	return 0;
}