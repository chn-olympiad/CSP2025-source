#include<bits/stdc++.h>
using namespace std;
int n,q;
map<char,vector<pair<string,string>>>mp;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1[0]].push_back(make_pair(s1,s2));
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1>>s2;
		int lens1=s1.length();
		int lens2=s2.length();
		if(lens1!=lens2){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<lens1;j++){
			for(int k=0;k<mp[s1[j]].size();k++){
				string t1=mp[s1[j]][k].first,t2=mp[s1[j]][k].second;
				int lent1=t1.length();
				if(j+lent1-1>=lens1) continue;
				if(t1==s1.substr(j,lent1)){
					string tmp=s1;
					s1.replace(s1.begin()+j,s1.begin()+j+lent1,t2);
//					cout<<">>|"<<s1<<' '<<s2<<endl;
					if(s1==s2) ans++;
					s1=tmp;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

