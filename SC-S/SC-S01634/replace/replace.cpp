#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<__LINE__<<" : "<<#x<<" "<<x
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e4+5,mod=1e9+7;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
	vector<string> s1(n + 1), s2(n + 1);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i]; 
	}
	for(int i=1;i<=q;i++){
		string t1, t2; cin>>t1>>t2;
		ll ans = 0; 
		for(int j=1;j<=n;j++){
			for(int k=0;k<t1.size();k++){
				int o = k, p = 0;
				while(p != s1[j].size() && t1[o] == s1[j][p]){o ++; p ++;}
				if(p == s1[j].size()){
					string w = t1;
					for(int o=0;o<s1[j].size();o++){w[o + k] = s2[j][o];}
					if(w == t2){ans ++;}
				}
			}
		}
		cout<<ans<<"\n"; 
	}
    return 0; 
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
