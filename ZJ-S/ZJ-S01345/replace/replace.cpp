#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
using namespace std;
int t,n,q;
string s1,s2,t1,t2;
map<pair<string,string>,int> mp,vis;
void colse(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[{s1,s2}]++;
	}
	while(q--){
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		if(len1!=len2) cout<<0<<endl;
		else{
			int ret=0,bj1=0,bj2=0;
			for(int i=0;i<len1;i++){
				if(t1[i]!=t2[i]){
					bj1=i;
					break;
				}
			}
			for(int i=len1-1;i>0;i--){
				if(t1[i]!=t2[i]){
					bj2=i;
					break;
				}
			}
			for(int i=0;i<=bj1;i++){
				string s1="",s2="";
				for(int j=i;j<len2;j++){
					s1+=t1[j],s2+=t2[j];
					if(j>=bj2) ret+=mp[{s1,s2}];
				}
			}
			cout<<ret<<endl;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	colse();
	t=1;
	while(t--) solve();
	return 0;
}