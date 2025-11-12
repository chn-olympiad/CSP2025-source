#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int a[N],n,ans;
void bfs(int x,int now,int step,int k){
	if(now>n){
		return ;
	}
	if(step>=3 and now==n){
		if(x>k*2){
			ans++;
		}
	}
	bfs(x+a[now+1],now+1,step+1,a[now+1]);
	bfs(x,now+1,step,k);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bfs(0,0,0,0);
	cout<<ans;
	return 0;
}
/*
1 1   1
2 3   2 1
3 7   3 3  1
4 10  4 6  3  1
5 29  5 10 10 3 1
6     6 15 20   3 1
                  3
                  */
