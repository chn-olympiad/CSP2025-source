#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=5e3+10;
int yy[N][N],n,a[N],ans;
void dfs(int k,int sum,int ma,int cnt){
	if(n+1==k){
//		cout<<sum<<" "<<ma<<" "<<cnt<<endl;
		if(cnt>=3&&sum>2*ma){
			ans++;
			if(ans==mod) ans=0;
		} 
		return;
	}
	dfs(k+1,sum+a[k],max(ma,a[k]),cnt+1);
	dfs(k+1,sum,ma,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=25){
		dfs(1,0,0,0);
		cout<<ans;
	}else{
		yy[1][1]=yy[2][1]=yy[2][2]=1;
		for(int i=3;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				yy[i][j]=(yy[i-1][j]+yy[i-1][j-1])%mod;
			}
		}
//		for(int i=1;i<=n+1;i++){
//			for(int j=1;j<=i;j++){
//				cout<<yy[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=3;i<=n;i++){
			ans+=yy[n+1][i+1];
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
