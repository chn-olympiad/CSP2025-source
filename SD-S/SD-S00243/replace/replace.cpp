#include<bits/stdc++.h> 
#define ll long long
using namespace std;

ll n,q;
map<string,string> m;
ll ans=0;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string x="",y="";
	while(n--){
		cin>>x>>y;
		m[x]=y;
	}
	ll pos=0;
	while(q--){
		ans=0;
		cin>>x>>y;
		string pre="";
		for(map<string,string>::iterator it=m.begin();it!=m.end();it++){
			pre=it->first;
			pos=0;
			while(1){
				pos=x.find(pre,pos);
				if(pos==-1)    break;
				string tmp=x.substr(0,pos)+it->second+x.substr(pos+pre.size());
				if(tmp==y){
					ans++;
					break;
				}
				pos+=pre.size();
			}
		}
   		cout<<ans<<endl;
	}
	return 0;
}

