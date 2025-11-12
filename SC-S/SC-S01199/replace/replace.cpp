#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
struct node{
	string c1,c2;
}ax[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s11,s12;
		cin>>s11>>s12;
		ax[i].c1=s11;
		ax[i].c2=s12;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
		}else{
			int ans=0;
			int st,ed;
			for(int i=0;i<s1.size();++i){
				if(s1[i]!=s2[i]){
					st=i;
					break;
				}
			}
			for(int i=s1.size()-1;i>=0;--i){
				if(s1[i]!=s2[i]){
					ed=i;
					break;
				}
			}
			string ss1="",ss2="";
			for(int i=st;i<=ed;++i){
				ss1+=s1[i];
				ss2+=s2[i];
			}
			for(int i=1;i<=n;++i){
				string sw1=ax[i].c1;
				string sw2=ax[i].c2;
				if(sw1.find(ss1)!=-1){
					if(sw2.find(ss2)!=-1){
						++ans;
					}
				}
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}