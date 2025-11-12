#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>a;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;a[s1]=s2;
	}while(q--){
		cin>>s1>>s2;int c=0;
		for(auto&i:a){
			int p=s1.find(i.first),l=i.first.size();
			if(p!=-1){
				string s=s1.substr(p,l);
				s1.replace(p,l,i.second);
				c+=(s1==s2);
				s1.replace(p,l,s);
			}
		}cout<<c<<'\n';
	}return 0;
}
