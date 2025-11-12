#include<bits/stdc++.h>
using namespace std;
#define end '\n'
#define ll long long 
const int N = 5005;
int a[N][3];
int vis[N];
void solve () {
	int n;
	cin >> n;
	for(int i=1; i <=n;i++) {
		cin >>a[i][0] >>a[i][1]>>a[i][2];
	}
	int ans=0;
	
	
	for(int i=0;i<(1ll << n);i++) {
		bitset<200>s(i);
		if(s.count() > n / 2) continue;
		
		for(int j=0;j<(1ll << n);j++){
			bitset<200>s1(j);
			if(s1.count() > n / 2) continue;
			
			for(int k = 0;k<(1ll << n);k++){
				int ok = 0;
				bitset<200>s2(k);
				int sum=0;
				memset(vis,0,sizeof(vis));
				if(s2.count() > n / 2) continue;
				
				for(int l= 0;l<n;l++)
					if(s[l]) vis[l+1]++;
				for(int l= 0;l<n;l++)
					if(s1[l]) vis[l+1]++;
				
				for(int l= 0;l<n;l++)
					if(s2[l]) vis[l+1]++;
				for(int i=1;i<=n;i++) if(vis[i]>=2) {
					ok=1;
					break;
				}
				if(ok) continue;
				for(int l = 0; l<n;l++)
					if(s[l]==1) sum += a[l + 1][0];
				for(int l = 0; l<n;l++)
					if(s1[l]==1) sum += a[l + 1][1];
				for(int l = 0; l<n;l++)
					if(s2[l]==1) sum += a[l + 1][2];
				ans=max(ans, sum);
			}
		}
				 
	}
	cout <<ans <<endl;
}

signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 1;
	cin >>t;
	while(t --) solve();
	
	
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/