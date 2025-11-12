#include<bits/stdc++.h>
using namespace std;
typedef vector<string>::iterator iter;
const int N=2e5+10;
unordered_map<string,vector<string>>v;
int n,q;
void solve(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size()){
		cout<<"0\n";
		return;
	}
	int ans=0,len=s1.size();
	if(len>1000){
		cout<<"0\n";
		return;
	}
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			string s=s1.substr(i,j-i+1);
			for(iter it=v[s].begin();it!=v[s].end();it++){
				string tmp=s1;
				tmp.replace(i,j-i+1,*it);
				//cout<<tmp<<"\n"; 
				if(tmp==s2) ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		v[s1].push_back(s2);
	}
	while(q--){
		solve();
	}
	return 0;
}
