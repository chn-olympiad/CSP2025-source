#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
vector<string>s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string t1,t2;
		cin>>t1>>t2;
		s1.push_back(t1),s2.push_back(t2);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int f1,f2,ans=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				f1=i;
				break;
			}
		}
		for(int i=0;i<t1.size();i++){
			if(t1[t1.size()-i]!=t2[t1.size()-i]){
				f2=t1.size()-i;
				break;
			}
		}
		for(int i=0;i<=f1;i++){
			for(int j=f2;j<t1.size();j++){
				string k1=t1.substr(i,j-i+1),k2=t2.substr(i,j-i+1);
				for(int k=0;k<n;k++){
					if(s1[k]==k1&&s2[k]==k2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
4 2
xabcx xadex
aa bb
ab bc
bc de
xabcx xadex
aaaa bbbb
*/

