#include <bits/stdc++.h>
#define int long long
#define pii std::pair<int,int>
using namespace std;

const int N = 1000050;

int n,q;
string s1[N],s2[N];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	
	for(int T=1;T<=q;T++) {
		int cnt=0;
		string q1,q2;
		cin>>q1>>q2;
		for(int i=1;i<=n;i++) {
			string tmp=q1;
			auto pos=q1.find(s1[i]);
			if(pos==std::string::npos) continue;
			int pos1=pos;
			int length=s1[i].size();
			for(int j=pos1;j<pos1+length;j++) tmp[j]=s2[i][j-pos1];
			if(tmp==q2) ++cnt;
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}
