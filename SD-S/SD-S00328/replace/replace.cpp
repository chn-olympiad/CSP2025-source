#include<bits/stdc++.h>
using namespace std;
using ld=long double;
#define int long long
#define endl "\n"
#define timn double(clock())/CLOCKS_PER_SEC

const int N=2e5+5,M=3005,inf=1e18;

int n,q,len[2][N];
string s[2][N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ld tim=double(clock())/CLOCKS_PER_SEC;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		len[0][i]=s[0][i].size();
		len[1][i]=s[1][i].size();
		s[0][i]=" "+s[0][i];
		s[1][i]=" "+s[1][i];
	}
	while(q--){
		string t1,t0; cin>>t0>>t1;
		int len0=t0.size(),len1=t1.size(),ans=0;
		t0=" "+t0; t1=" "+t1;
		for(int i=1;i<=n;i++){
			int flskp=0;
			if(len[0][i]>len0) continue;
			for(int j=1;j<=t1.size()-s[0][i].size()+1;j++){
				string t=t0;
				for(int k=j;k<=j+len[0][i]-1;k++){
					if(s[0][i][k-j+1]!=t[k]||s[1][i][k-j+1]!=t1[k]) break;
					t[k]=s[1][i][k-j+1];
				}
				if(t==t1) ans++;
				if(timn-tim>0.97){
					flskp=1;
					break;
				}
			}
			if(flskp) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
