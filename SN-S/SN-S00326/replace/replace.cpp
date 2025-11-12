#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t1.size()<s[j][1].size()) continue;
			for(int k=0;k+s[j][1].size()-1<t1.size();k++){
				if(t1.substr(k,s[j][1].size())==s[j][1]){
					string z=t1;
					for(int ss=k;ss<=k+s[j][1].size()-1;ss++) z[ss]=s[j][2][ss-k];
					if(z==t2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

