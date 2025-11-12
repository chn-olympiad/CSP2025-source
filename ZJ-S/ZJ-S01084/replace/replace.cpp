#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int ans;
bool vis[200005];
void f(string t1,string t2){
	for(int i=0;i<t1.size();i++){
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			if(t1.substr(i,s1[j].size())==s1[j]&&t2.substr(i,s2[j].size())==s2[j]){
				vis[j]=1;
				f(t1.substr(i+s1[j].size()),t2.substr(i+s2[j].size()));
				vis[j]=0;
			}
		}
		if(t1[i]!=t2[i]){
			return;
		}
	}
	ans++;
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		f(t1,t2);
		cout<<ans<<endl;
	}
	return 0;
}
