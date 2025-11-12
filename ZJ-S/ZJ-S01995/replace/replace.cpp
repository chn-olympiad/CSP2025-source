#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int hs=13331;
int n,q,l,r,hs1,hs2,ans;
string s1,s2,s3,s4;
map<pair<int,int>,int>mp;
inline int cal(string s){
	int x=0;
	for(int i=0;i<s.size();i++)x=hs*x+s[i];
	return x;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;l=r=0;
		for(int j=1;j<=s1.size();j++){
			if(!l&&s1[j-1]!=s2[j-1])l=j;
			if(s1[j-1]!=s2[j-1])r=j;
		}
		s3=s4="";
		for(int j=l-1;j<r;j++)s3+=s1[j],s4+=s2[j];
		hs1=cal(s3);hs2=cal(s4);mp[{hs1,hs2}]++;
	}
	for(;q;q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){cout<<"0\n";continue;}
		l=r=0;
		for(int j=1;j<=s1.size();j++){
			if(!l&&s1[j-1]!=s2[j-1])l=j;
			if(s1[j-1]!=s2[j-1])r=j;
		}
		s3=s4="";
		for(int j=l-1;j<r;j++)s3+=s1[j],s4+=s2[j];
		hs1=cal(s3);hs2=cal(s4);
		cout<<mp[{hs1,hs2}]<<'\n';
	}
	return 0;
}
