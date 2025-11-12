#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;

ll n,q;
string s[N][3],t1,t2;
map<string,string>mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]=s[i][2];
	}
	while(q--){
		ll ans=0;
		cin>>t1>>t2;
		for(int l=0;l<t1.size();l++){
			string x="",y="",z="",temp="";
			for(int r=0;r<l;r++) x=x+t1[r];
			for(int r=l;r<t1.size();r++){
				temp=temp+t1[r];
				for(int rr=r+1;rr<t1.size();rr++) z=z+t1[rr];
				y=mp[temp];
				string nnn=x+y+z;
				z="";
				if(nnn==t2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
