#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll T,n;
struct nd{
	ll na,nb,nc;
} arr[100005];
ll ans;
void dfs(ll ca,ll cb,ll cc,ll num,ll sum){
	if(ca > n/2 || cb > n/2 || cc > n/2)
		return;
	if(num == n+1){
		ans = max(ans,sum);
		return;
	}
	dfs(ca+1,cb,cc,num+1,sum+arr[num].na);
	dfs(ca,cb+1,cc,num+1,sum+arr[num].nb);
	dfs(ca,cb,cc+1,num+1,sum+arr[num].nc);
}
bool cmp1(nd a,nd b){
	return a.na-a.nb > b.na-b.nb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		ans = 0;
		for(ll i = 1 ; i <= n ; ++i){
			cin >> arr[i].na >> arr[i].nb >> arr[i].nc;
		}
		if(n <= 30){
			dfs(0,0,0,1,0);
			cout << ans << endl;
		} else {
			sort(arr+1,arr+1+n,cmp1);
			for(ll i = 1 ; i <= n/2 ; ++i){
				ans += arr[i].na;
//				cout << arr[i].na << " " << arr[]
			}
			for(ll i = n/2+1 ; i <= n ; ++i){
				ans += arr[i].nb;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
