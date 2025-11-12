//张皓涵 SN-S00248 西安高新第一中学南校区 

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
pair <int,int> st;
pair <int,int> st1;
int d = 0;
int b = 0;
int s[N] = {};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,g,ans,maxa,maxb,maxc;
	cin >> t;
	cin >> n;
	cin >> st.first >>st.second;
	cin >> st1.first>>st1.second;
	int maxn = max(st.first,st1.first);
	int maxn1 = max(st.second,st1.second);
	cout << maxn+maxn1;		
	if(s[0]>s[1]){
		s[0] = maxa;
		cout << maxa;
	}maxa = s[1];
	if(s[1] >s[2]){
		s[1] = s[1];
	}else maxb = s[2];
	//ans = maxb+maxa;
	//cout << ans;
	for(int k=0;k < t;k++){
		//cout << ans << endl;
	}
	return 0;
}
