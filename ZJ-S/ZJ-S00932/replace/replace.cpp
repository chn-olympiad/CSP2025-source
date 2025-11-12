#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
int n,q,ans;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	For(i,1,n){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int len=x.size();
		ans=0;
		For(i,0,len-1)
			For(j,1,len-i){
				string s=x.substr(i,j);
				if(mp[s]!=""){
					string t=x.substr(0,i)+mp[s]+x.substr(i+j,len-(i+j));
					if(t==y) ans++;
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
