#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[10000],s[10000],vis[10000];
int ans=0;

void dfs(int num,int ls,int sum, int mx){
	if (num>=3 && sum>2*mx){
		ans=(ans+1)%998244353;
	}
	if (num>n || ls>n) return;
	for (int i=ls+1;i<=n;i++){
		if (vis[i]==0){
			int dnum=num+1,dls=i,dsum=sum+a[i],dmx=max(mx,a[i]);
			vis[i]=1;
			dfs(dnum,dls,dsum,dmx);
			vis[i]=0;
		}
	}
}

signed main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int mx=-1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=s[i-1]+a[i];
		mx=max(mx,a[i]);
	}
	if (s[n]<=2*mx){
		cout << '0';
		return 0;
	}
	for (int i=1;i<=n;i++){
		dfs(1,i,a[i],a[i]);
	}
	cout << (ans%998244353);
	return 0;
}
