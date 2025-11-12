#include<bits/stdc++.h>
using namespace std;
int n,qwer1fsdd;
pair<string,string>a[200005];
string s1,s2;
int p;
int ans;
signed main(){
//	freopen("csps/down/replace/replace3.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> qwer1fsdd;
	for(int i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
	while(qwer1fsdd--){
		ans=0;
		p=-1;
		cin >> s1 >> s2;
		for(int i=1;i<=n;i++){
			while(1){
				p=s1.find(a[i].first,p+1);
				if(p==-1)break;
				ans+=s1.substr(0,p)+a[i].second+s1.substr(p+a[i].first.length())==s2;
//				cout << s1.substr(0,p)+a[i].second+s1.substr(p+a[i].first.length()) << "\n";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

