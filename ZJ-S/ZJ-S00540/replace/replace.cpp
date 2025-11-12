#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+9;
string div(string s,int l,int r){
	string as="";
	for(int i=l;i<=r;i++){
		as.push_back(s[i]);
	}
	if(l>r) return "";
	return as;
}
string comb(string a,string b,string c){
	string as="";
	for(int i=0;i<a.length();i++){
		as.push_back(a[i]);
	}
	for(int i=0;i<=b.length();i++){
		as.push_back(b[i]);
	}
	for(int i=0;i<=c.length();i++){
		as.push_back(c[i]);
	}
	return as;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	long long ans=0;
	map<string,string> mp;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	//cout<<"kkk";
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()) continue;
		for(int j=0;j<s2.length();j++){
			for(int l=1;l<s2.length();l++){
				int k=j+l-1;
				string y=div(s1,j,k);
				string x=div(s1,0,j-1);
				string z=div(s1,k+1,s1.length());
				//cout<<y<<'\n';
				if(mp.find(y)!=mp.end()){
					y=mp[y];
					string d=comb(x,y,z);
					if(d==s2) ans++;
					//cout<<"dddd "<<d<<endl;
				}
				
				
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
