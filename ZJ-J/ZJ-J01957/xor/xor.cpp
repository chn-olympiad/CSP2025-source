#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
constexpr int maxn = 5e5+3;
int n,k;
int a[maxn],s[maxn];
int main(){
	IOS;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = (s[i-1]^a[i]);
	}
	int lst = 0,ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = i;j > lst;j--)
			if((s[i]^s[j-1]) == k){
				lst = i;
				ans++;
				break;
			}
	cout << ans;
	return 0;
}