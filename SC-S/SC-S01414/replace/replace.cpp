#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244617;
string s[200010];
string t[200010],a,b;
int n,q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		s[i]=' '+s[i];
		t[i]=' '+t[i];
	}
	for(int RND=1;RND<=q;RND++){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		a=' '+a,b=' '+b;
		int len=a.size()-1,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=len;j++){
				if(a[j-1]!=b[j-1])break;
				bool opt=1;
				for(int k=1;k<=s[i].size();k++){
					if(a[k+j-1]!=s[i][k]){opt=0;break;}
					if(b[k+j-1]!=t[i][k]){opt=0;break;}
				}
				if(opt==1){
					for(int k=j+s[i].size()-1;k<=len;k++){
						if(a[k]!=b[k]){
							opt=0;break;
						}
					}
					ans+=opt;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}