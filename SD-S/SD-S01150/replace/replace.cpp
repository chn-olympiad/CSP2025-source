#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
using namespace std;
int n,q;
string a,b;
unordered_map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		cin>>a>>b;
		int la=a.length(),lb=b.length(),ans=0;
		if(la>=10000){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<la;++i){
			int r=i;
			string now="";
			while(r<lb){
				now+=a[r];
				if(mp.find(now)!=mp.end()&&a.substr(0,i)+mp[now]+a.substr(r+1,la-r-1)==b)
					ans++;
				r++;
			}
		}
		cout<<ans<<"\n";
	}
	cout<<endl;
	return 0;
}
