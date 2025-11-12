#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,arr[105];
ll cnt,num,ans1,ans2;
bool cmp(ll a,ll b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n*m ; ++i){
		cin >> arr[i];
	}
	num = arr[1];
	sort(arr+1,arr+1+n*m,cmp);
	ll l = 1,r = n*m+1,mid;
	while(l < r){
		mid = (r-l)/2+l;
		if(arr[mid] > num)
			l = mid+1;
		else
			r = mid;
	}
	cnt = l;
	ans1 = (cnt+n-1)/n;
	ans2 = cnt % n;
	if(ans2 == 0)
		ans2 = n;
	if(ans1 % 2 == 0)
		ans2 = n-ans2+1;
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
