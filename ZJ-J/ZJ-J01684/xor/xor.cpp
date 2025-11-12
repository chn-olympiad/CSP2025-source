#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,k,ans,x,now;
int f[N],vis[N];
vector<int> a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>x;
		f[i]=f[i-1]^x;
		a[f[i]].push_back(i);
	}
	now=-1;
	for(int i=1;i<=n;i++){
		int t=f[i]^k;
		bool flag=0;
		for(int j=vis[t];j<a[t].size();j++){
			if(a[t][j]>=i) break;
			if(a[t][j]<now) continue;
			vis[t]=j;
			now=i;
			flag=1;
			break;
		}
		if(flag==1) ans++;
	}
	cout<<ans;
	return 0;
}