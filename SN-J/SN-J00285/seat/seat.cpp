#include <bits/stdc++.h>
#define pii pair<int,int>
#define fir first
#define sec second
#define IO ios::sync_with_stdio(0);cin.tie(0);
//#define int long long
#define clr(x) memset(x,0,sizeof(x))
#define cmax(x) memset(x,0x3f,sizeof(x))
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define finf -0x3f3f3f3f
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define maxn 150
#define lowbit(x) (x & (-x))
//#define mod 998244353
#define ll long long
#define endl '\n'
using namespace std;
ll n,m;
ll a[maxn];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	ll tot = a[1],now = 0;
	sort(a + 1,a + n * m + 1,cmp);
	for(ll i = 1;i <= n * m;i++){
		if(a[i] == tot){
			now = i;
			break;
		}
	}
	ll p = now % n;
	ll h = now / n;
	if(p){
		h++;
	}else{
		p = n;
	}
//	cout << h << " " << p << endl;
	if(h & 1){
		cout << h << " " << p << endl;
	}else{
		cout << h << " " << n - p + 1 << endl;
	}
	return 0;
}
