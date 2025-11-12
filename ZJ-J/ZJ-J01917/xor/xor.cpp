#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
unordered_map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	if (n<=10000){
		int ans=0;
		for (int i=1; i<=n; i++){
			int cnt=0;
			int num=0;
			bool fl=1;
			for (int j=i; j<=n; j++){
				if (fl){
					num=a[j];
					fl=0;
				}else{
					num^=a[j];
				}
				if (num==m){
					fl=1;
					cnt++;
				}
			}
			ans=max(cnt,ans);
		}
		cout<<ans<<"\n";
	}else{
		int ans=0;
		int maxx=0;
		for (const auto &x:mp){
			if (x.second>maxx){
				maxx=x.second;
				ans=x.first;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}