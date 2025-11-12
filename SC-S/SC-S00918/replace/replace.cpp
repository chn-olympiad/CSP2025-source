#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string a[21145],b[21145];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}int ans=0;
	while(m--){
		ans=0;
		string s,g;
		cin>>s>>g;
		for(int i=1;i<=n;i++){
			int k=s.find(a[i]);
			if(k>=s.size()||k<0)continue;
			string h=s.substr(0,k),o=s.substr(k+a[i].size());
			string d=h+b[i]+o;
			if(d==g)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}