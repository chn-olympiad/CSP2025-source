#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,h,maxx,s;
int ah[100005][3];
int b_member[100005];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n;
	while(n--) {
		cin>>s;
		int cnt=0;
		maxx=-0x3f3f3f3f;
		for(int i=1; i<=s; i++) {
			for(int j=1; j<=3; j++) {
				cin>>ah[i][j];
				maxx=max(ah[i][j],maxx);
				b_member[i]=maxx;
			}
			cnt+=b_member[i];
			maxx=-0x3f3f3f3f;
		}
		cout<<cnt<<"\n";
		memset(ah,0,sizeof ah);
		memset(b_member,0,sizeof(b_member));
	}
	return 0;
}

