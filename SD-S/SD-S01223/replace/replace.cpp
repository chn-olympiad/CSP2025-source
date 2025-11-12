#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define ll long long
int n,q,ans;
string s[N],s1[N];
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i]>>s1[i];
	}while(q--){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();++i){
			for(int j=1;j<=n;++j){
				if(a.substr(i,s[j].size())==s[j]){
					ans+=((a.substr(0,i)+s1[j]+a.substr(i+s[j].size(),a.size())==b)?1:0);
				}
			}
		}cout<<ans<<'\n';ans=0;
	}cout<<endl;
	return 0;
} 
