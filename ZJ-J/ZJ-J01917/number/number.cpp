#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[12];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for (const auto &ch:s){
		if ('0'<=ch && ch<='9'){
			cnt[ch-'0']++;
		}
	}
	for (int i=9; i>=0; i--){
		if (cnt[i]){
			while (cnt[i]--){
				cout<<i;
			}
		}
	}
	cout<<"\n";
	return 0;
}
