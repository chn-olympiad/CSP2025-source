#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		ans=0;
		cin>>t[1]>>t[2];
		for (int i=1;i<=n;i++){
			int p=t[1].size()-1,l=s[i][1].size()-1;
			for (int j=0;j<p-l+1;j++){
				if (t[1].substr(j,l+1)==s[i][1]){
					string str=t[1].substr(0,j)+s[i][2]+t[1].substr(j+l+1);
					if (str==t[2]){
						ans++;
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

