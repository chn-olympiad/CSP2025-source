#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 998244353;
ll n,m,arr[505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	ll y = 0;
	bool flag = 1;
	ll len = strlen(s);
	for(ll i = 0 ; i < len ; ++i){
		if(s[i] == 0){
			flag = 0;
			break;
		}
	}
	for(ll i = 1 ; i <= n ; ++i){
		cin >> arr[i];
		if(arr[i] > 0)
			y++;
	}
	if(flag){
		if(y >= m){
			ll ans = 1;
			for(ll i = n ; i >= 1 ; --i){
				ans = ((ans%mod)*(i%mod))%mod;
			}
			cout << ans << endl;
		} else {
			cout << 0 << endl;
		}
	} else {
		cout << 0 << endl;
	}
	return 0;
}
/*
froepen fropen frepen
#include<bits\stdc++.h>
诈骗这一块

讲个故事：
我有一个朋友，他在考试前骂了图灵两句，结果得到了两个CE。
这个故事告诉我们：信图灵，不爆零。
总之祝大家Rp++ QwQ
(I believe that my Chinese words can see... I wish it QaQ)
*/
