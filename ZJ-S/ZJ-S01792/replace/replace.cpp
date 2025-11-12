#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s,t;
		cin>>s>>t;
		mp[s]=t;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int sum=0;
		map<string,string>::iterator it;
		for(it=mp.begin();it!=mp.end();it++){
			if(a.find(it->first)!=string::npos){
				int temp=a.find(it->first);
				string s=it->second,t=a;
				a=a.substr(0,temp)+s+a.substr(temp+s.size());
				if(a==b) sum++;
				a=t;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
