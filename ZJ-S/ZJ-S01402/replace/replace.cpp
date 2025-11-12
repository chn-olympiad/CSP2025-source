#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t[200005][3],x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		for(int j=0;j<t[i][1].size();j++){
			for(int k=j;k<t[i][1].size();k++){
				for(int l=1;l<=n;l++){
					if(t[i][1].substr(j,k-j+1)==s[l][1]){
						x=t[i][1].substr(0,j)+s[l][2]+t[i][1].substr(k+1,t[i][1].size()-k-1);
						if(x==t[i][2])ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

