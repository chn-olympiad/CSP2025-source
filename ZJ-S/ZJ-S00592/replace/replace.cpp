#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,a[200001];
string s[200001][2],t[200001][2];
vector<int>b[200001];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	getline(cin,s[1][1]);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int cnt=-1,lst=0;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				a[i]++;
				b[i].push_back(j-lst);
				lst=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		vector<int>f;
		cin>>t[i][0]>>t[i][1];
		int x=0;
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<endl;
			continue;
		}
		int lst=0;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j]){
				x++;
				f.push_back(j-lst);
				lst=j;
			}
		}
		for(int k=1;k<=n;k++){
			if(x!=a[k])continue;
			bool flg=0;
			for(int j=1;j<x;j++){
				if(b[k][j]!=f[j]){
					flg=1;
					break;
				}
			}
			if(flg)continue;
			for(int j=0;j<s[k][0].size();j++){
				int l=f[0]-b[k][0];
				if(t[i][0][l+j]!=s[k][0][j]||t[i][1][l+j]!=s[k][1][j]){
					flg=1;
					break;
				}
			}
			if(!flg)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//11.1 17:33
//code by K.S.
//want 50 pts.
