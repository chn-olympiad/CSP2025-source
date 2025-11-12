//100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+50;
struct node{
	int d1,d2;
	ll val;
	bool operator< (const node &a) const{
		return val > a.val;
	}
}b;
int a[N];
int root(int pos){
	if(a[pos] == pos) return pos;
	a[pos] = root(a[pos]);
	return a[pos];
}
ll vil[N][11];
ll vilval[11];
node kru[N];
int cnt;
int k,n;
priority_queue<node> q;
ll ansi;
inline void addd(int pos){
	for(int i = 1;i <= cnt;i++) q.push(kru[i]);
	for(int i = k;i > 0;i--){
		if((pos >> (i-1))&1){
			b.d1 = i+n;
			for(int j = 1;j <= n;j++){
				b.d2 = j;
				b.val = vil[j][i];
				q.push(b);
			}
			ansi += vilval[i];
		}
		
	}
}
ll ans;
inline void krusul(){
	for(int i = 1;i <= n+k;i++) a[i] = i;
	int r1,r2;
	while(!q.empty()){
		b = q.top();
		q.pop();
		r1 = root(a[b.d1]);
		r2 = root(a[b.d2]);
		if(r1 == r2) continue;
		a[max(r1,r2)] = min(r1,r2);
		ansi += b.val;
	}
	ans = min(ans,ansi);
}

int m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> b.d1 >> b.d2 >> b.val;
		q.push(b);
	}
	for(int i = 1;i <= n;i++) a[i] = i;
	int r1,r2;
	while(!q.empty()){
		b = q.top();
		q.pop();
		r1 = root(a[b.d1]);
		r2 = root(a[b.d2]);
		if(r1 == r2) continue;
		a[max(r1,r2)] = min(r1,r2);
		kru[++cnt] = b;
		ans += b.val;
	}
//	cout <<ans << '\n';
	for(int i = 1;i <= k;i++){
		cin >> vilval[i];
		for(int j = 1;j <= n;j++){ 
			cin >> vil[j][i];
		}
	}
	for(int i = 1;i < (1 << k);i++){
		ansi = 0;
		addd(i);
		krusul();
//		cout << ansi << '\n';
	}
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

