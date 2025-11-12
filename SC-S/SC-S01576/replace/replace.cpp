#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q,ans,mx_diff;
string l,r,s[2][N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		mx_diff=max(mx_diff,(int)s[0][i].size());
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>l>>r;
		if(l.size()!=r.size()){
			cout<<0<<'\n';
			continue;
		}
		int diff=0;
		for(int i=0;i<l.size();i++){
			if(l[i]!=r[i]){
				diff++;
			}
		}
		if(diff>mx_diff){
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++){
			bool fl=0;
			int now=0,cost=0;
			for(int k=0;k<l.size();k++){
				if(l[k]==s[0][j][now]&&r[k]==s[1][j][now]){
					now++;
				}
				else{
					now=0;
				}
				if(now==s[0][j].size()){
					fl=1;
					cost++;
					now=0;
				}
			}
			if(fl==1&&cost==1){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}