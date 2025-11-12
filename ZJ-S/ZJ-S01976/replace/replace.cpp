#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string>a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	while(q--){
		string s,ss;cin>>s>>ss;long long ans=0;
		if(s.size()!=ss.size()){cout<<"0\n";continue;}
		for(int i=1;i<=n;i++){
			int l=s.find(a[i].first);
			while(l!=-1){
				string o=s.substr(0,l),p=s.substr(l,(a[i].first).size()),q=s.substr(l+(a[i].first).size(),s.size()-l-(a[i].first).size());
				if(ss==(o+a[i].second+q))ans++;
				l=s.find(a[i].first,l+1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
