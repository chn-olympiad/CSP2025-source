#include<bits/stdc++.h>
#define int long long
const int Mod=998244353;
using namespace std;
int n,a[5010],ans,pow2[5010],s[5010],f[5010][10010];
int dfs(int x,int k) {
	if(f[x][k+5000])return f[x][k+5000];
	if(k<0)return pow2[n-x+1];
	if(x==n) {
		if(k<0)return 2;
		else if(k<a[x])return 1;
		else return 0;
	}
	if(s[x]<=k)return 0;
	f[x][k+5000]=dfs(x+1,k)+dfs(x+1,k-a[x]);
//	cout<<x<<" "<<k<<" "<<f[x][k+5000]<<"\n";//1
	return f[x][k+5000];
}
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	pow2[0]=1;
	for(int i=1; i<=n; i++)pow2[i]=pow2[i-1]*2%Mod;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=n; i>=1; i--)s[i]=s[i+1]+a[i];
	for(int i=1; i<=n-2; i++) {
		for(int j=i+1; j<=n-1; j++) {
//			cout<<"\n"<<i<<" "<<j<<"\n";//1
//			if(a[j]+a[j+1]>a[i]) {
//				int r=n,l=j+1,mid;
//				while(l<r) {
//					mid=r+l+1>>1;
//					if(a[j]+a[mid]>a[i])l=mid;
//					else r=mid-1;
//					cout<<l<<" "<<r<<" "<<mid<<"\n";
//				}
//				ans+=pow2[n-j]-pow2[n-l];
//				ans=ans%Mod;
//			} else 
			if(s[j]>a[i]) {
				ans+=dfs(j+1,a[i]-a[j])%Mod;
				ans=ans%Mod;
			} else break;
//			cout<<ans<<"\n";//1
		}
	}
	cout<<ans;
	return 0;
}
//operator
//priority_queue<int> q;
