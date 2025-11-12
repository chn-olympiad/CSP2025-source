#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+7;

string s[N],s1[N],t,tt;
int n,q;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	while(q--){
		cin>>t>>tt;
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=s[i].size();
			for(int j=0;j<(int)t.size()-len+1;j++){
				string d=t.substr(j,len);
				if(d==s[i]){
					string f=t;
					for(int k=j;k<=j+len-1;k++) f[k]=s1[i][k-j];
					if(f==tt) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
