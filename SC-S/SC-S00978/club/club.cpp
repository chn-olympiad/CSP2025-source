#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n ,ca = 0 ,cb = 0 ,cc = 0 ,ans = 0;
	cin>>n;
	vector<pair<ll ,ll>> a(n+1) ,b(n+1) ,c(n+1) ,na(n+1) ,nb(n+1) ,nc(n+1);
	vector<bool> used(n+1 ,0);
	struct node{
		ll a ,b ,c;
	};
	vector<node> x(n+1);
	for(ll i = 1;i <= n;i++){
		cin>>a[i].first>>b[i].first>>c[i].first;
		a[i].second = b[i].second = c[i].second = i;
		x[i].a = a[i].first ,x[i].b = b[i].first ,x[i].c = c[i].first;
		na[i] = a[i];
		nb[i] = b[i];
		nc[i] = c[i];
	}
	sort(x.begin()+1 ,x.end() ,[&](node a ,node b){
		return max({a.a ,a.b ,a.c}) > max({b.a ,b.b ,b.c});
	});
	sort(a.begin()+1 ,a.end() ,[&](pair<ll ,ll> a ,pair<ll ,ll> b){
		return a.first > b.first;
	});
	sort(b.begin()+1 ,b.end() ,[&](pair<ll ,ll> a ,pair<ll ,ll> b){
		return a.first > b.first;
	});
	sort(c.begin()+1 ,c.end() ,[&](pair<ll ,ll> a ,pair<ll ,ll> b){
		return a.first > b.first;
	});
	ll suma = 0 ,sumb = 0 ,sumc = 0;
	for(ll i = 1;i <= n/2;i++){
		suma += a[i].first;
		sumb += b[i].first;
		sumc += c[i].first;
	}
	ll ansa = suma;
	for(ll i = 1;i <= n/2;i++){
		used[a[i].second] = 1;
	}
	for(ll i = 1;i <= n;i++){
		if(!used[i]){
			ansa += max(nb[i].first ,nc[i].first);
			used[i] = 1;
		}
	}
	ll ansb = sumb;
	for(ll i = 1;i <= n/2;i++){
		used[b[i].second] = 0;
	}
	for(ll i = 1;i <= n;i++){
		if(used[i]){
			ansb += max(na[i].first ,nc[i].first);
			used[i] = 0;
		}
	}	
	ll ansc = sumc;
	for(ll i = 1;i <= n/2;i++){
		used[c[i].second] = 1;
	}
	for(ll i = 1;i <= n;i++){
		if(!used[i]){
			ansc += max(na[i].first ,nb[i].first);
			used[i] = 1;
		}
	}
	for(ll i = 1;i <= n;i++){
		if(max({x[i].a ,x[i].b ,x[i].c}) == x[i].a){
			ans += x[i].a;
			ca++;
		}
		else if((max({x[i].a ,x[i].b ,x[i].c}) == x[i].b)){
			ans += x[i].b;
			cb++;
		}
		else{
			ans += x[i].c;
			cc++;
		}
	}
	for(ll i = n;i >= 1;i--){
		if(ca > n/2){
			ca--;
			ans -= x[i].a;
			if(x[i].b > x[i].c){
				cb++;
				ans += x[i].b;
			}
			else{
				cc++;
				ans += x[i].c;
			}
		}
		if(cb > n/2){
			cb--;
			ans -= x[i].b;
			if(x[i].a > x[i].c){
				ca++;
				ans += x[i].a;
			}
			else{
				cc++;
				ans += x[i].c;
			}
		}
		if(cc > n/2){
			cc--;
			ans -= x[i].c;
			if(x[i].a > x[i].b){
				ca++;
				ans += x[i].a;
			}
			else{
				cb++;
				ans += x[i].b;
			}
		}
	}
	cout<<max({ansa ,ansb ,ansc ,ans})<<"\n";		
}

signed main(){
	freopen("club.in" ,"r" ,stdin);
	freopen("club.out" ,"w" ,stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}