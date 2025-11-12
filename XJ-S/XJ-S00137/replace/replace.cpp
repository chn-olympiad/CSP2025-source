#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,db[5000005];
map<string,string>mp;
vector<string>vec;
string search(string x,string y){
	string u=mp[x],pok=y;
	//cout<<x<<" "<<y<<' '<<u<<"\n";
	for(int i=0;i<y.size();i++){
		if(y[i]==x[0]){
			for(int j=1;j<x.size();j++){
				if(y[i+j]!=x[j]) break;
				if(j==x.size()-1){
					for(int k=i;k<=i+x.size()-1;k++){
						pok[k]=u[k-i];
						//cout<<k<<": "<<pok[k]<<"\n";
					}
					//cout<<pok<<"\n";
					return pok;
				}
			}
		}
	}
	return "0";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(max(n,q)<=100){
		while(n--){
			string x,y;
			cin>>x>>y;
			mp[x]=y;
			vec.push_back(x);
		}
		while(q--){
			int ans=0;
			string x,y;
			cin>>x>>y;
			for(auto u:vec){
				string hik=search(u,x);
				if(hik==y) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(n--){
		string x,y;
		cin>>x>>y;
		int dxb=0,dyb=0;
		for(int i=0;i<x.size();i++){
			if(x[i]=='b') dxb=i;
			if(y[i]=='b') dyb=i;
			if(dxb&&dyb) break;
		}
		db[dxb-dyb+2500000]++;
	}
	while(q--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		int dxb=0,dyb=0;
		for(int i=0;i<x.size();i++){
			if(x[i]=='b') dxb=i;
			if(y[i]=='b') dyb=i;
			if(dxb&&dyb) break;
		}
		ans+=db[dxb-dyb+2500000];
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
