#include<bits/stdc++.h>
using namespace std;

const int NM = 2e5;
string s1[NM+4],s2[NM+4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i = 1;i <= n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;cin>>t1>>t2;
		int ans = 0;
		string gh = t1;
		for(int i = 1;i <= n;i++){
			int flag = t1.find(s1[i]);
			if(flag != -1){
				int len = s2[i].length();
				for(int j = 0;j < len;j++) t1[j+flag] = s2[i][j];
				if(t1 == t2) ans++;
				t1 = gh;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
