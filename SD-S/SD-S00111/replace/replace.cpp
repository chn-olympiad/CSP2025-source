#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=t1.find(s1[i]);
			if(pos!=-1){
				int spos=pos,epos=pos+s1[i].size()-1;
				string qs=t1.substr(0,spos),hs=t1.substr(epos+1,t1.size()-1-epos);
				string s="";
				s=qs+s2[i];
				s=s+hs;
				if(s==t2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
