#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,mod=998244353;
int n,q,a[N],cnt;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string c1,c2;
		int ans=0;
		cin>>c1>>c2;
		for(int j=1;j<=n;j++){
			string s=s1[j];
			if(c1.size()+s2[j].size()-s.size()!=c2.size()) continue;
			for(int k=0;k<c1.size();k++){
				if(c1[k]==s[0]);
				int f=1,ii;
				for(ii=0;ii<s.size();ii++){
					if(c1[k+ii] != s[ii]){
						f=0;
						break;
					}
				}
				if(f==1){
					int fl=1;
					int cnt=k+s2[j].size();
					for(int l=k;l<=cnt-1;l++){
						if(s2[j][l-k]!=c2[l]){
							fl=0;
							break;
						}
					}
					if(fl==1){
						for(int l=cnt;l<c2.size();l++){
							if(c1[l-cnt+k+ii]!=c2[l]){
								fl=0;
								break;
							}
						
						}
						if(fl==1){
							ans++;
						}
					}
					
				}
				if(c1[k]!=c2[k]) break;
			}
		}
		cout<<ans<<endl;
	}
}