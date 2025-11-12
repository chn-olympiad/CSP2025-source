#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[200005],b[200005];
map<pair<int,int>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		long long ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			string tmp=s1.substr(0,s1.find(a[i]))+b[i]+s1.substr(s1.find(a[i])+a[i].size(),s1.size()-s1.find(a[i])-a[i].size());
			if(tmp==s2){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
