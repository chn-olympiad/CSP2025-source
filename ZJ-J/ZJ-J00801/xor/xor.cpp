#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,k,a[500005],x[500005],f[500005],h[300],ans;
bitset<300> v;
signed main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	bool t = 1;
	for(int i = 1;i <= n;i++) {
		cin >> a[i],x[i]=x[i-1]^a[i];
		if(a[i] > 1) t = 0;
	}
	if(n <= 1000){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= i;j++){
				if((x[i]^x[j-1])==k) f[i]=max(f[i],f[j-1]+1);
				else f[i]=max(f[i],f[j-1]);
			}
		}
		int maxn = 0;
		for(int i = 1;i <= n;i++) maxn= max(maxn,f[i]);
		cout << maxn << "\n";
	}
	else if(t == 1 && k <= 1){
		if(k==0){
			for(int i = 1;i <= n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i]==1&&a[i+1]==1)ans++,i++;
				}
			}
			cout << ans << "\n";
		}
		else{
			for(int i = 1;i <= n;i++){
				if(a[i]==1) ans++;
			}
			cout << ans << "\n";
		}
		return 0;
	}
	else{
		for(int i = 1;i <= n;i++){
			v[0]=1;h[0]=i-1;
			vector <pair<int,int> > g;
			for(int j = 0;j <= 255;j++){
				if(v[j]) g.push_back({j,h[j]});
			}
			for(int j = 0;j <= 255;j++){
				h[j]=-1;
			}
			v.reset();
			for(auto y : g){
				int l = y.first;
				v[l^a[i]] = 1;
				int id = y.second;
				if((l^a[i])==k)f[i]=max(f[i],f[id]+1);
				else f[i]=max(f[i],f[id]);
				h[l^a[i]]=id;
			}
		}
		int maxn = 0;
		for(int i = 1;i <= n;i++) maxn= max(maxn,f[i]);
		cout << maxn << "\n";
	}
	return 0;
}
