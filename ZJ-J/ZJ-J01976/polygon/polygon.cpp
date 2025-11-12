#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244353;
int n,a[N],cnt;
void dfs(int x,int sum,int mx){
	if(x>n)return;
	if(mx!=0 && sum>2*mx){
		cnt++;
	}
	dfs(x+1,sum,mx);
	dfs(x+1,sum+a[x],max(mx,a[x]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx1=max(mx1,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*mx1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(mx1==1){
		cout<<n-2;
	}else{
//		build(1,1,n);
		dfs(0,0,0); 
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(j-i+1<3)continue;
//				if(ask1(1,i,j)>2*ask2(1,i,j)){
//					cnt++;
//					cnt%=mod;
//				}
//			}
//		}
		cout<<cnt;
	}
	return 0;
}
