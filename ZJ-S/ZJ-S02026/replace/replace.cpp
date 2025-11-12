#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=5e5+10;
string s[N],t[N];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		string a,b; cin>>a>>b;
		int len=a.size(),ans=0;
		for(int i=1;i<=n;i++){
			int lenx=s[i].size();
			for(int j=0;j+lenx-1<a.size();j++){
				if(a.substr(j,lenx)==s[i]){
					string to=a.substr(0,j)+t[i]+a.substr(j+lenx,len-(j+lenx)+1);
					if(to==b) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
