#include<bits/stdc++.h>
#include<set>
#include<string>
#include<vector>
using namespace std;
int n,q;
pair<string,string> makepair(string a,string b){
	pair<string,string> temp={a,b};
	return temp;
}
vector<int> re;
void fd(string a,string b){
	for(int i=0;i<a.length()&&i+b.length()<=a.length() ;i++){
		for(int j=0;j<b.length() ;j++){
			if(a[i+j]!=b[j]) break;
			if(j==b.length()-1) re.push_back(i);
			
		}
	}
}
set<pair<string,string> > s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s.insert(makepair(s1,s2)); 
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length() ){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(auto x:s){
			string s1=x.first,s2=x.second;
			if(s1.length()>t1.length() ){
				continue;
			}
			re.clear();
			fd(t1,s1);
			for(auto y:re){
				string rt1=t1;
				rt1.erase(rt1.begin() +y,rt1.end() );
				string rt2=t1;
				rt2.erase(rt2.begin() ,rt2.begin() +y+s1.length() );
				string rt3=rt1+s2+rt2;
				if(rt3==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
