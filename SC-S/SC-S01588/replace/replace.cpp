#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,q,ans;
map<string,string> m1;
map<string,bool> m2;
string stru(string s,int i,int j){
	string r;
	for(int k=i;k<=j;++k) r+=s[k];
	return r;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		m1[s1]=s2;
		m2[s1]=1;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		ans=0;
		for(int i=0;i<s1.length();++i){
			for(int j=i;j<s1.length();++j){
				string p=stru(s1,i,j);
				//cout<<p<<" ";
				if(!m2[p]) continue;
				else{
					string x=stru(s1,0,i-1);
					string y=m1[p];
					string z=stru(s1,j+1,s1.length()-1);
				//	cout<<x<<" "<<y<<" "<<z<<" ";
					string s3=x+y+z;
				//	cout<<s3<<"\n";
					if(s3==s2) ans++;
				}	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
