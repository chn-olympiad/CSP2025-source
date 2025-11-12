#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
int b[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
        cin>>s[i][1];
        cin>>s[i][2];
	}
	while(q--){
		string t,tt;
		cin>>t>>tt;
		if(t.size()!=tt.size()){
			cout<<0<<endl;
			continue;
		}
		int x=t.size();
		t=' '+t;
		tt=' '+tt;
		int ans=0;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=n;j++){
				int k=1;
				if(i+s[j][1].size()-1>n)continue;
				for(int z=i;z<=i+s[j][1].size()-1;z++){
					if(t[i]!=s[j][1][z-i]){
						k=0;
						break;
					}
				}
				if(k==1){
					for(int z=i;z<=i+s[j][1].size()-1;z++){
						if(s[j][2][z-i]!=tt[z]){
							k=0;
							break;
						}
					}
					if(k==1){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
