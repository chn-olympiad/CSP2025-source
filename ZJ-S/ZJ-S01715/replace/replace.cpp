#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int val;
	string str;
};
map<string,node> mp;
int n,q,ans,l,r;
string sta,stb;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sta>>stb;
		mp[sta].str=stb;
		mp[sta].val=1;
	}
	while(q--){
		cin>>sta>>stb;
		ans=0;
		for(int i=0;i<sta.size();i++){
			if(sta[i]!=stb[i]){
				l=i;
				break;
			}
		}
		for(int i=sta.size()-1;i>=0;i--){
			if(sta[i]!=stb[i]){
				r=i;
				break;
			}
		}
		for(int i=0;i<=l;i++){
			for(int j=r;j<sta.size();j++){
				int len=j-i+1;
				string st1=sta.substr(i,len);
				string st2=stb.substr(i,len);
				if(mp[st1].val&&mp[st1].str==st2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}