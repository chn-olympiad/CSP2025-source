#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define sf std :: flush
#define lowbit(x) (x & (-x))
#define endl '\n'
const int N = 2e5 + 10;
string s[N],t[N];
int n,q;
bool check(string u,string v,int st,int id){
	int len = u.length();
	for(int i = 0;i < len;i++){
		if(i >= st && i < st + s[id].length()){
			if(s[id][i-st] != u[i] || t[id][i-st] != v[i]) return false;
		}
		else if(u[i] != v[i]) return false;
	}
	return true;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i] >> t[i];
	while(q--){
		string S,T; cin >> S >> T;
		if(S.length() != T.length()) cout<<0<<endl;
		else{
			int ans = 0;
			for(int i = 0;i < S.length();i++){
				for(int j = 1;j <= n;j++){
					if(s[j].length() + i > S.length()) continue;
					ans += check(S,T,i,j);
				}
			}
			cout<<ans<<endl;
		}
	}
	cout<<sf;
    fclose(stdin);
    fclose(stdout);
	return 0;
}


