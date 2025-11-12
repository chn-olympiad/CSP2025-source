#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][2],t1,t2;
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		for(int j=1;j<=n;j++){
			if(t1.find(s[j][0])<t1.size()){
				if(t1.find(s[j][0])==t2.find(s[j][1])){
					string s1=t1.erase(t1.find(s[j][0]),t1.find(s[j][0])+s[j][0].size());
					string s2=t2.erase(t2.find(s[j][1]),t2.find(s[j][1])+s[j][1].size());
					if(s1==s2){
						ans++;
					}
				}
			}
		}cout<<ans<<'\n';
	}
}
