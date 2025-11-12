#include<bits/stdc++.h>
#include<map>
using namespace std;
long long n,m,k;string s,x,y,z,t;
map<string,bool>b;map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s>>t;
		b[s]=1;mp[s]=t;
	}for (int o=1;o<=m;o++){
		cin>>s>>t;k=0;
		for (int i=0;i<s.size();i++) for (int j=i+1;j<=s.size();j++){
			x=s.substr(0,i);y=s.substr(i,j-i);z=s.substr(j,s.size()-j);
			if (b[y]) y=mp[y];
			x=x+y+z;
			if (x==t) k++;
		}cout<<k<<"\n";
	}
}