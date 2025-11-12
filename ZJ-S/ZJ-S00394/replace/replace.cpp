#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5 + 10;
map< pair<string,string> , int> mp;
int n,Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> Q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[{s1,s2}] ++ ;
	}
	for(int i=1;i<=Q;i++){
		string t1,t2;
		cin >> t1 >> t2;
		int L,R,L_,R_;
		L = 1,R = t1.size();
		L_ = 1,R_ = t2.size();
		t1 = " " + t1;
		t2 = " " + t2;
		while(t1[L] == t2[L_]){
			L ++ ;
			L_ ++ ;
		}
		while(t1[R] == t2[R_]){
			R -- ;
			R_ -- ;
		}
		LL ans = 0;
		string nw1,nw2;
		nw1 = nw2 = "";
		for(int j=L;j<=R;j++)
			nw1 += t1[j];
		for(int j=L_;j<=R_;j++)
			nw2 += t2[j];
		ans += mp[{nw1,nw2}];
		for(int k=0;k<L;k++){
			if(k > 0){
				nw1 = t1[L-k]+nw1;
				nw2 = t2[L_-k]+nw2;
			}
			string t = nw2;
			string tt = nw1;
			for(int l=0;R+l<=n+1;l++){
				// cout << tt << " " << t << "\n";
				if(l ==0 && k == 0) continue;
				if(l == 0) ans += mp[{nw1,t}];
				else{
					t += t2[R_+l];
					tt += t2[R+l];
					ans += mp[{tt,t}];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}