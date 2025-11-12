#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
string a[3][maxn];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[1][i] >> a[2][i];
	}
	while(q--){
		int ans=0;
		cin >> s1 >> s2;
		for(int i=1;i<=n;i++){
			if(a[1][i]==s1&&a[2][i]==s2) ans++;
			else{
				for(int j=0;j<s1.size()-a[1][i].size();j++){
					int f=0;
					if(s1[j]==a[1][i][0]){
						for(int k=j;k<=j+a[1][i].size()-1;k++){
							if(a[1][i][k-j]!=s1[k]||a[2][i][k-j]!=s2[k]){
								f=1;
							}
						}
					}
					if(!f){
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}