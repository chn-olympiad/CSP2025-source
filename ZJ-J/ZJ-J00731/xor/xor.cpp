#include <bits/stdc++.h>
using namespace std;
long long n,k,a[6000],f[5010],ma,dp[5010];
vector<int> b[5010];
long long yh(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	int xx[30],yy[30],tx=0,ty=0,ans=0;
	while(x!=0){
		xx[++tx]=x%2;
		x/=2;
	}
	while(y!=0){
		yy[++ty]=y%2;
		y/=2;
	}
	if(tx>ty) while(tx>ty) ans=ans*2+xx[tx--];
	if(tx<ty) while(tx<ty) ans=ans*2+yy[ty--];
	for(int i=ty;i>=1;i--) ans=ans*2+(xx[i]!=yy[i]);
	return ans; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long mx=0;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	if(mx<=1){
		int ans=0;
		if(k!=0&&k!=1){
			cout<<0;
			return 0;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i-1]==1) ans++,a[i]=0;
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++)
				ans+=a[i];
			cout<<ans;
		}
		return 0;
	}
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		f[i]=yh(f[i-1],a[i]);
		if(f[i]==k) b[1].push_back(i);
		for(int j=2;j<=i;j++){
			long long x=yh(f[i],f[j-1]);
			if(x==k) b[j].push_back(i-j+1);
 		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<b[i].size();j++){
			dp[i]=max(dp[i],dp[i-1]);
			dp[i+b[i][j]]=max(dp[i+b[i][j]],dp[i]+1);
		}
	ma=0;
	for(int i=1;i<=n+1;i++) ma=max(ma,dp[i]);
	cout<<ma;
	return 0;
}
