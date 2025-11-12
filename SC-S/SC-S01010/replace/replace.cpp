#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=5e6+5;
int n,q,slen[N],tlen;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		slen[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		tlen=t1.size();
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j+slen[i]<=tlen;++j){
//				cout<<i<<','<<j<<':'<<t1.substr(j,slen[i])<<' '<<t1.substr(0,j)+s2[i]+t1.substr(j+slen[i],tlen-j-slen[i])<<'\n';
				if(t1.substr(j,slen[i])==s1[i]&&t1.substr(0,j)+s2[i]+t1.substr(j+slen[i],tlen-j-slen[i])==t2)
					++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}