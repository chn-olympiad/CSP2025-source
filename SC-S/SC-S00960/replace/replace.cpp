#include <bits/stdc++.h>
using namespace std;
int n,q;
map<string,vector<string>>mp;
string a,b;
string work(int l,int r){
	string res;
	for(int i=l;i<=r;i++){
		res+=a[i];
	}
	return res;
}
string u(int l,int r,string mid){
	string res;
	for(int i=0;i<l;i++){
		res+=a[i];
	}
	res+=mid;
	for(int i=r+1;i<a.size();i++){
		res+=a[i];
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a].push_back(b);
	}
	while(q--){
		int ans=0;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			for(int j=i;j<a.size();j++){
				string c=work(i,j);
				if(mp.find(c)!=mp.end()){
					for(string ch:mp[c]){
						if(u(i,j,ch)==b)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}