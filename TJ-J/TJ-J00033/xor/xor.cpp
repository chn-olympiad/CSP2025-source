#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[501000],vis[501000];

signed main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	int ans=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]==k) ans++,vis[i]=1;
	}
	int tmp=0;
	for (int l=1,r=1;r<=n || l<=n;r++){
		if (vis[l]==1){
			tmp=0;
			l++;
			continue;
		}
		if (vis[r]==1){
			tmp=0;
			r++;
			l=r;
			continue;
		}
		if (r==n) l++,r=l;
		if (l>n || r>n) continue;
		tmp=tmp^a[r];
		if (tmp==k){
			tmp=0;
			ans++;
			for (int i=l;i<=r;i++) vis[i]=1;
			r++;
			l=r;
		}
	}
	cout << ans;
	return 0;
}
