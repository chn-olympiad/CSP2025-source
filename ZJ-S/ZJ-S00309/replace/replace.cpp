#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int l,r;
string s[N][2],a,b,sa,sb;
void solve(){
	cin>>a>>b;
	int ans=0;
	if(a.size()!=b.size()){
		puts("0");
		return ;
	}
	int len=a.size();
	l=-1,r=0;
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			if(l==-1) l=i;
			r=i;
		}
	}
//	cout<<l<<"--"<<r<<endl;
	for(int i=0;i<=l;i++){
		for(int j=1;j<=n;j++){
			if(i+s[j][0].size()<=r) continue;
			if(a[i]==s[j][0][0]&&b[i]==s[j][1][0]){
				bool oo=true;//
				for(int k=1;k<s[j][0].size();k++){
					if(a[i+k]!=s[j][0][k]||b[i+k]!=s[j][1][k]){
						oo=false;
						break;
					}
				}
				if(oo){
				//	cout<<j<<endl;
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		solve();
	}
	return 0;
}
