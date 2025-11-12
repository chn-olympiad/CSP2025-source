#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
struct stu{
	int a, b, c;
	int mxnm;
	char mxcb;
}r[10010];
bool cmp(stu a, stu b){
	return a.mxnm > b.mxnm;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		memset(r,sizeof(r),0);
		int n;
		cin >> n;
		int mex = n/2;
		cout << mex << '\n';
		for(int i = 1; i <= n; i++){
			cin >> r[i].a >> r[i].b >> r[i].c;
			r[i].mxnm = max(r[i].a, max(r[i].b, r[i].c));
			if(r[i].mxnm==r[i].a){r[i].mxcb = 'a'; continue;}
			else if(r[i].mxnm==r[i].b){r[i].mxcb = 'b'; continue;}
			else if(r[i].mxnm==r[i].c){r[i].mxcb = 'c'; continue;}
		}
		sort(r+1, r+n+1, cmp);
		int acnt, bcnt, ccnt;
		int ans = 0;
		acnt = bcnt = ccnt = 0;
		for(int i = 1; i <= mex; i++){
			ans += r[j].a;
		}
		cout << ans << '\n';
	}
	return 0;
}
