#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int M=5e6+2,N=2e5+2;
int n,q;
string s[N][2],t[N][2];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		ll ans=0;
		cin>>t[i][0]>>t[i][1];
		for(int j=1;j<=n;j++){
			int sz=(int)s[j][0].size();
			for(int k=0;k<t[i][0].size()-sz+1;k++){
				if(t[i][0].substr(k,sz)==s[j][0]&&s[j][1]==t[i][1].substr(k,sz)){
					if(t[i][0].substr(0,k)+s[j][1]+t[i][0].substr(k+sz,(int)t[i][0].size()-(k+sz))==t[i][1])ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
