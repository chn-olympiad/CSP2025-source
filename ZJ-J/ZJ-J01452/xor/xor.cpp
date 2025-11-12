#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k,a[N],s[N],ans;
bool mp[N << 2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int de = 0;
	for (int i = 1;i <= n;++ i){
		int x = k ^ s[i] ^ s[de];
		if (mp[x] || x == 0){
			for (int j = de + 1;j <= i;++ j){
				mp[s[j] ^ s[de]] = 0;
			}
			de = i;
			ans ++;
		}
		else {
			mp[s[i] ^ s[de]] = 1;
		}
	}
	cout<<ans;
	return 0;
}