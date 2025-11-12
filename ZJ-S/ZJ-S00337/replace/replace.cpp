#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string S,T;cin>>S>>T;
		if(n>=1000){
			cout<<"0\n";continue;
		}
		int L=S.size();S=" "+S;T=" "+T;
		int ans=0;
		for(int l=1;l<=L;l++){
			for(int r=l;r<=L;r++){
				for(int i=1;i<=n;i++){
					if(s[i][0].size()!=r-l+1) continue;
					bool flag=false;
					for(int j=l;j<=r;j++){
						if(S[j]!=s[i][0][j-l]){
							flag=true;break;
						}
					}
					if(flag) continue;
					flag=true;
					for(int j=1;j<=L;j++){
						char ch=0;
						if(l<=j&&j<=r) ch=s[i][1][j-l];
						else ch=S[j];
						if(ch!=T[j]){
							flag=false;break;
						}
					}
					if(flag) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

