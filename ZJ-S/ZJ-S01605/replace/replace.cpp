#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,q,ans=0;
string s[N],to[N],t,g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>to[i];
	while(q--){
		cin>>t>>g;
		ans=0;
		for(int i=1;i<=n;i++){
			string cz=t;
			if(t.length()<s[i].length()) continue;
			for(int j=0;j<=(t.length()-s[i].length());j++){
				if(t[j]==s[i][0]){
					bool b=true;
					for(int k=1;k<s[i].length();k++){
						if(t[j+k]!=s[i][k]){
							b=false;
							break;
						}
					}
					if(b){
						for(int k=0;k<s[i].length();k++) cz[j+k]=to[i][k];
						if(cz==g){
//							cout<<s[i]<<endl;
							ans++;
							break;
						}
						cz=t;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}