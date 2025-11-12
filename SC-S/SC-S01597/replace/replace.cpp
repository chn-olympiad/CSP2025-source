#include<bits/stdc++.h>
#define ll long long
#define pss pair<string,string>
using namespace std;
int n,q;
map<string,string> chance;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		chance[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
		}else{
			string res1="",res2="";
			for(int j=0;j<s1.size();j++){
				if(s1[j]!=s2[j]){
					res1+=s1[j],res2+=s2[j];
				}
			}
			int ans=0;
			for(auto [c1,c2]:chance){
				if(s1.find(c1)>=s1.size() or s2.find(c2)>=s2.size()) ans+=0;
				else{
					if(res1.size()>c1.size() or res2.size()>c2.size()) ans+=0;
					else if(c1.find(res1)>=c1.size() or c2.find(res2)>=c2.size()) ans+=0; 
					else ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}