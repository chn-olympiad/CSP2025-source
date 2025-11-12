#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,Q;
string A[N],B[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1; i<=n; i++) {
		cin>>A[i]>>B[i];
	}
	while(Q--) {
		int ans=0;
		string a,b;
		cin>>a>>b;
		queue<string> q;
		q.push(a);
		while(!q.empty()) {
			string s=q.front();
			q.pop();
			if(s==b) {
				ans++;
				continue;
			}
			for(int i=1; i<=n; i++) {
				for(int j=0; j<s.length(); j++) {
					string sub="";
					for(int k=j;k<A[i].length() and k<s.length();k++){
						sub+=s[k];
					}
					if(sub==A[i]) {
						for(int k=0; k<s.length(); k++) {
							s[k]=B[i][k];
						}
						q.push(s);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

