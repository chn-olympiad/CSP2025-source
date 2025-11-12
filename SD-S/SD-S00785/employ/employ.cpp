//8
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n" 
const int mod = 998244353;
int n,m;
char s[505]; 
int c[505];
int ans;
int p[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		//cout << s[i] << " ";
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
		p[i] = i;
	}
	if(n <= 20){
		do{
			int quit = 0;
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(quit >= c[p[i]]) quit ++;
				else if(s[i] == '0') quit ++;
				else cnt ++;
			}
			//cout << cnt << " " << quit << endl;
			ans += (cnt >= m);
			ans %= mod;
		}while(next_permutation(p + 1,p + n + 1));
		cout << ans;
	}else{
		while(clock() < 0.95 * CLOCKS_PER_SEC){
			random_shuffle(p + 1,p + n + 1);
			int quit = 0;
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(quit >= c[p[i]]) quit ++;
				else if(s[i] == '0') quit ++;
				else cnt ++;
			}
			//cout << cnt << " " << quit << endl;
			ans += (cnt >= m);
			ans %= mod;
		}
		cout << ans;
	} 
	return 0;
} 
