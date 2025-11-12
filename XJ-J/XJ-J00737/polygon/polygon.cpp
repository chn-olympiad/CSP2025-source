#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5010,mod=998244353;
int a[N];
int n;
int ans=0;
bool flag=false;
LL st[N][N];

void solve(int idx,int maxv,int sum){
	if(idx>n){
		if(sum>2*maxv){
			ans++;
		}
		return;
	}
	solve(idx+1,maxv,sum);
	solve(idx+1,max(maxv,a[idx]),sum+a[idx]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=true;
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i/2+5;j++){
		  		if(j)st[i][j]=(st[i-1][j]+st[i-1][j-1])%mod;
	 			else st[i][j]=1;
			}
			st[i][i]=1;
		}
		for(int i=3;i<=n;i++){
			int tmp=i;
			if(i>=n/2){
				tmp=n-i;
			}
			ans=(ans+st[n][tmp])%mod;
		}
		cout<<ans;
		return 0;
	}
	solve(1,0,0);
	cout<<ans;
	return 0;
}
