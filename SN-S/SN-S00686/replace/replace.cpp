#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		mp[ss1]=ss2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string tt1,tt2;
		cin>>tt1>>tt2;
		for(int i=0;i<tt1.size();i++){
			for(int j=i;j<tt1.size();j++){
				string k=tt1.substr(i,j-i+1);
				string t=tt1.substr(0,i)+mp[k]+tt1.substr(j+1,tt1.size()-j);
				if(t==tt2)ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
} 
