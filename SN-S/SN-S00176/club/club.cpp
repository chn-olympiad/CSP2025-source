#include <bits/stdc++.h>
#define maxn 100010
#define ll long long
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
//#define int long long
#define lowbit(x) (x & (-x))
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
ll T = 1;
ll n,m;
ll a[maxn][3];
struct node{
	int mx,cmx,p;
}b[maxn];
bool cmp(int x,int y){
	return b[x].mx - b[x].cmx > b[y].mx - b[y].cmx; 
}
vector <int> v[3];
ll ans = 0;
void solve(){
	for(int i = 0;i <= 2;i++){
		v[i].clear();
	}
    cin >> n;
    ans = 0;
	for(ll i = 1;i <= n;i++){
		b[i].mx = b[i].cmx = b[i].p = 0;
		for(ll j = 0;j <= 2;j++){
			cin >> a[i][j];
			if(a[i][j] > b[i].mx){
				b[i].cmx = b[i].mx;
				b[i].mx = a[i][j];
				b[i].p = j;
			}else if(a[i][j] > b[i].cmx){
				b[i].cmx = a[i][j];
			}
		}
		v[b[i].p].push_back(i);
		ans += b[i].mx;
	}
//	cout << ans << " ";
	ll tot = -1;	
	for(ll i = 0;i <= 2;i++){
		if((ll)(v[i].size()) > n / 2){
			tot = i;
			break;
		}
	}
	if(tot == -1){
		cout << ans << endl;
		return ;
	}
	sort(v[tot].begin(),v[tot].end(),cmp);
	for(ll i = n / 2;i < (ll)v[tot].size();i++){
		ans -= b[v[tot][i]].mx - b[v[tot][i]].cmx;
	}
	cout << ans << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
    while(T--){
    	solve();
	}	
}
