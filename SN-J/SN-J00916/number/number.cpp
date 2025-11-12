#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int sum[50];
bool sc = false;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i++)
		if(s[i] >= '0' && s[i] <= '9')
			sum[s[i]-'0']++;
	for(int i = 9;i >= 0;i--){
		int cnt = sum[i];
		if(cnt == 0)
			continue;
		if(i != 0 && cnt > 0)
			sc = true;
		if(i != 0){
			for(int j = 1;j <= cnt;j++)
				cout << i;
		}
		else if(sc){
			for(int j = 1;j <= cnt;j++)
				cout << i;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
/* 
	               ◢◤
	           ◢▆◤
	   ◢   ◢▇◤
	 ◢▇▆▇◤
	 ◥▇▇◤
     Just Do It
   尽管我无法证明他的对错，
   	   但我坚信他是对的
*/
