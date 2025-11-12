#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],v[N][N],vis[N][N],ans,sum;
int dp(int l,int mx){
	if(mx<0) mx=-1;
	if(vis[l][mx+1]){
		//cout<<v[l][mx+1];
		return v[l][mx+1];
	}
	int cnt=0;
	if(mx<0){
		cnt++;
	}
	for(int i=1;i<l;i++){
		cnt=(cnt+dp(i,mx-a[i]))%998244353;
	}
	v[l][mx+1]=cnt%998244353;
	vis[l][mx+1]=1;
	return cnt%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		sum=0;
		//memset(v,0,sizeof(v));
		ans=(ans+dp(i,a[i]))%998244353;
	}
	cout<<ans%998244353;
	return 0;
} 
