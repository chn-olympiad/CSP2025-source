#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[100005],t,n;
int a[4][100005],tot,ans;
void solve(int k1,int k2,int k3,int an,int i){
	if(i>n){
		ans=max(ans,an);
		return;
	}
	if(k1<n/2)solve(k1+1,k2,k3,an+a[1][i],i+1);
	if(k2<n/2)solve(k1,k2+1,k3,an+a[2][i],i+1);
	if(k3<n/2)solve(k1,k2,k3+1,an+a[3][i],i+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		solve(0,0,0,0,1);
		cout<<ans;
		ans=0;
	}
	return 0;
}
/*
0 1 0
0 1 0
0 2 0
0 2 0
dp 
1 2 3 4

4 2 1
3 2 4
5 3 4
3 5 1
dp
4 8 13 18

10 9 8
4 0 0
dp
10 13

*/