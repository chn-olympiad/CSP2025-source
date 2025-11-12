#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[10010][3],a,b;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i][1]>>s[i][2];
	}
	while(q--) {
		long long ans=0;
		cin>>a>>b;
		int l=a.size();
		for(int i=1; i<=n; i++) {
			if(s[i][1].size()>l) continue;
			int len=s[i][1].size();
			for(int j=0; j+len-1<a.size(); j++) {
				if(j>0&&a[j-1]!=b[j-1]) break;
				int q=0;
				while(q<s[i][1].size()&&a[j+q]==s[i][1][q]&&b[j+q]==s[i][2][q]) {
					q++;
				}
				bool flg=1;
				for(int cc=j+q;cc<a.size();cc++){
					if(a[cc]!=b[cc]){
						flg=0;
						break;
					} 
				}
				if(q==s[i][1].size()&&flg) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
