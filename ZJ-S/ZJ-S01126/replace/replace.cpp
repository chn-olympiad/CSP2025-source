#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		mp[s]=s1;
	}
	//cout<<mp.size()<<endl;
	while(q--){
		string s,t;
		cin>>s>>t;
		string l="";
		ll ans=0;
		int len=s.size();
		for(int i=0;i<s.size();i++){
			string k="";
			for(int j=i;j<s.size();j++){
				k+=s[j];
				auto it=mp.find(k);
				if(it!=mp.end()){
					string mid=mp[k];
					string d=s.substr(j+1,len-1);
					string o=l+mid;
					o=o+d;
					//cout<<l<<" "<<k<<" "<<d<<endl;
					if(o==t){
						ans++;
					}
				}
			}
			l+=s[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
