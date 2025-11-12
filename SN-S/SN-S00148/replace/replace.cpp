#include<bits/stdc++.h>
using namespace std;
int n,q,lon[200001];
string s[200001][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n>> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		lon[i]=s[i][1].size();
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin >> t[0] >> t[1];
		int l=-1,r=t[0].size();
		while(t[1][l+1]==t[0][l+1])l++;
		while(t[1][r-1]==t[0][r-1])r--;
		for(int j=-1;j<=l;j++){
			for(int k=t[0].size()+1;k>=r;k--){
				for(int o=1;o<=n;o++){
					if(lon[o]==k-j-1){
						bool f=1;
						for(int u=0;u<lon[o];u++){
							if(s[o][0][u]!=t[0][j+1+u]||s[o][1][u]!=t[1][j+1+u]){
								f=0;
								break;
							}
						}if(f)ans++;
					}
				}
			}
		}cout << ans << "\n";
	}
	
	return 0;
}
