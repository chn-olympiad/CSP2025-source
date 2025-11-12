#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(auto x:mp){
			string q=x.first;
			if(a==q&&b==x.second){
				ans++;
				//cout<<"qqq"<<endl;
				continue;
			}
			int j=-1;
			
			if(a.substr(j+1,(int)q.size())==q&&b.substr(j+1,(int)q.size())==x.second){
				//cout<<x.first<<" "<<j<<" "<<a.substr(j+1,(int)q.size())<<"-"<<q<<endl;
				//cout<<a.substr((int)q.size())<<endl;
				if(a.substr(j+(int)q.size()+1,n)==b.substr(j+(int)q.size()+1)){
					ans++;
					//cout<<q<<" "<<q.size()<<endl;
				}
			}
			for(int j=0;j<a.size();j++){
				
				if(a[j]!=b[j]){
					break;
				}
				//cout<<a[j]<<" "<<j<<" "<<a.substr(j+1,(int)q.size())<<"-"<<q<<endl;
				if(a.substr(j+1,(int)q.size())==q&&b.substr(j+1,(int)q.size())==x.second){
				//	cout<<x.first<<" "<<j<<" "<<a.substr(j+1,(int)q.size())<<"-"<<q<<endl;
				//	cout<<a.substr(j+(int)q.size()+1)<<endl;
					if(a.substr(j+(int)q.size()+1)==b.substr(j+(int)q.size()+1)){
						ans++;
						//cout<<q<<" "<<q.size()<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
