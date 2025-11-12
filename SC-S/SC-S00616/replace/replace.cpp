#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct node{
	string ss1,ss2;
}a[200001];
//map<string,string>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
//		string s,ss;
//		cin >> s >> ss;
//		mp[s]=ss;
		cin >> a[i].ss1 >> a[i].ss2;
	}
	while(q--){
		int ans=0;
		string x,y;
		cin >> x >> y;
		if(x.length()!=y.length()){
			cout << 0 << "\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			string xx=x;
			int aa=x.find(a[i].ss1);
			if(aa==4294967295) continue;
			for(int j=0;j<a[i].ss2.length();j++){
				x[j+aa]=a[i].ss2[j];
			}
			if(x==y){
				ans++;
			}
			x=xx;
		}
		cout << ans << "\n";
	}
	return 0;
}