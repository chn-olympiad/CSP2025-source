#include<bits/stdc++.h>
using namespace std;
int n,q,ans;string s1,s2;
pair<string,string>l;
vector<string>ll;
map<pair<string,string>,vector<string>>mp;//unordered_
bool pd(string a,string b){
	return a.find(b)<1e9 ? 1:0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int j,k;
		for(j=0;s1[j]==s2[j];j++);
		for(k=s1.size()-1;s1[k]==s2[k];k--);
		string e,ee;
		for(int i=j;i<=k;i++){
			e=e+s1[i];ee=ee+s2[i];
		}
		l={e,ee};
		mp[l].push_back(s1);
	}for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int j,k;
		for(j=0;s1[j]==s2[j];j++);
		for(k=s1.size()-1;s1[k]==s2[k];k--);
		ans=0;string e,ee;
		for(int i=j;i<=k;i++){
			e=e+s1[i];ee=ee+s2[i];
		}
		l={e,ee};
		if(mp.count(l)>0){
			ll=mp[l];
			for(int i=0;i<ll.size();i++){
				if(pd(s1,ll[i])){
					ans++;
				}
			}
		}cout<<ans<<'\n';
	}
	
	return 0;
}
