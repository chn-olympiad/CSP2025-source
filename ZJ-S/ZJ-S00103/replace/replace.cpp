#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t1,t2;
bool check(string x,string y,int p){
	for(int i=p;i<x.size();i++){
		if(x[i]==y[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	scanf("%d%d",&n,&q);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
//		scanf("%s%s",&s[i][0],&s[i][1]);
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		int ans=0;
//		scanf("%s%s",&t1,&t2);
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=t1.size()-s[i][0].size();j++){
				if(t1[j]!=t2[j]&&t1[j]!=s[i][0][0]) break;
				if(t1[j]!=s[i][0][0]||t2.substr(j,s[i][0].size())!=s[i][1]) continue;
				if(t1.substr(j,s[i][0].size())==s[i][0]){
					if(j+s[i][0].size()==t1.size()){
						ans++;
						continue;
					}
					if( t1.substr(j+s[i][0].size()) == t2.substr(j+s[i][0].size()) ) ans++;
				}
				if(t1[j]!=t2[j]) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

