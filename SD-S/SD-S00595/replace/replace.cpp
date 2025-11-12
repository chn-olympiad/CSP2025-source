#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N],s2[N];
int dif[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
		int tot=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=s2[i][j]){
				tot++;
			}
		}
		dif[i]=tot;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				cnt++;
			}
		}
		int ans=0;
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				int f1=1;
				if(dif[j]!=cnt) continue;
				for(int k=0;k<s[j].size();k++){
					if(t1[i+k]!=s[j][k]){
						f1=0;
						break;
					}else{
						if(s2[j][k]!=t2[i+k]){
							f1=0;
							break;
						}
					}
				}
				if(f1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

