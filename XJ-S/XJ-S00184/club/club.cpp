#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n;
vector<int>s;
int satis1[N],satis2[N],satis3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		int ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
				cin >> satis1[i] >> satis2[i] >> satis3[i];
		}
		if(n == 2){
			int s[N];
			s[1] = satis1[1]+satis2[2];
			s[2] = satis1[1]+satis3[2];
			s[3] = satis2[1]+satis1[2];
			s[4] = satis2[1]+satis3[2];
			s[5] = satis3[1]+satis1[2];
			s[6] = satis3[1]+satis2[2];
			sort(s+1,s+6+1);
			cout << s[6] << endl;
		}else{
			sort(satis1+1,satis1+n+1);
			for(int i = n;i > n/2;i--){
				ans += satis1[i];
				}
			cout << ans << endl;
		}
	}
	return 0;
}
