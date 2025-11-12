#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,MOD=998244353;
int n,ans;
int a[N];
bool b=1;
void dfs(int k,int p,int sum){
	if(k>3&&sum>2*a[p]){
		ans++;
	}
	for(int i=p+1;i<=n;i++){
		dfs(k+1,i,sum+a[i]);
	}
}
int c(int x,int y){
	if(y*2>n)y=x-y;
	int sum=1;
	for(int i=x;i>=x-y+1;i--){
		sum*=i;
	}
	for(int i=y;i>=1;i--){
		sum/=i;
	}
	return sum%MOD;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)dfs(1,0,0);
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				b=0;
				break;
			}
		}
		if(b){
			for(int i=3;i<=n;i++){
				ans+=c(n,i);
			}
		}
	}
	cout<<ans%MOD;
	return 0;
}

