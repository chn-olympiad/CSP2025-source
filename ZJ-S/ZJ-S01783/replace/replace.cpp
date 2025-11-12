#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans,len,leni,j;
string s[200100],s2[200100],a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}while(m--){
		cin>>a>>b;
		ans=0;
		len=a.size();
		for(i=1;i<=n;i++){
			leni=s[i].size();
			for(j=0;j<len-leni+1;j++){
				if(j==0||a.substr(0,j-0)==b.substr(0,j-0)){
					if(a.substr(j,leni)==s[i]&&b.substr(j,leni)==s2[i]){
						if(a.substr(j+leni)==b.substr(j+leni)){
							ans++;
						}
					}
				}
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
