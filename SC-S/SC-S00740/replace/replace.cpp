#include<bits/stdc++.h>
//#pragma GCC	optimize(2)
using namespace std;

int n, q, ans;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	vector<pair<string, string> > s(n+1), pur(n+1);
	for(int i=1;i<=n;++i){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;++i){
		cin>>pur[i].first>>pur[i].second;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=q;++j){
			if(pur[j].first==s[i].first&&pur[j].second==s[i].second) ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}