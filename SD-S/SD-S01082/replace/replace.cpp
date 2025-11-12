#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string p[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>p[i][0]>>p[i][1];
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<(p[i][0].size());k++){
				if(p[i][0][k]==s[j][0][0]){
					int tot=0,tot2=k;
					bool f=0;
					string x=p[i][0];
					while(p[i][0][tot2]==s[j][0][tot]&&tot<s[j][0].size()){
						if(p[i][1][tot2]!=s[j][1][tot]){
							f=1;
							break;
						}
						x[tot2]=s[j][1][tot];
						tot2++;
						tot++;
					}
					if(f||x!=p[i][1]){
						continue;
					}else{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
