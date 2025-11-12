#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
class Student {
public:
	ll a, b, c;
};
ll n,ans;
vector<Student> sds;
vector<ll> as, bs, cs;
void print() {
	ll ans = 0;
	for (ll i : as) ans += sds[i].a;
	for (ll i : bs) ans += sds[i].b;
	for (ll i : cs) ans += sds[i].c;
	cout << ans << endl;
}
bool cmp(ll a,ll b){
	return sds[a].a>sds[b].a;
}
bool cmp1(ll a,ll b){
	return sds[a].a-sds[a].c>sds[b].a-sds[b].c;
}
bool cmp2(ll a,ll b){
	return sds[a].a-sds[a].b>sds[b].a-sds[b].b;
}
bool cmp3(ll a,ll b){
	return sds[a].b-sds[a].a>sds[b].b-sds[b].a;
}
bool cmp4(ll a,ll b){
	return sds[a].b-sds[a].c>sds[b].b-sds[b].c;
}
bool cmp5(ll a,ll b){
	return sds[a].c-sds[a].a>sds[b].c-sds[b].a;
}
bool cmp6(ll a,ll b){
	return sds[a].c-sds[a].b>sds[b].c-sds[b].b;
}
void atoc(){
	sort(as.begin(),as.end(),cmp1);
	for(ll i=as.size()-1;i>=n/2;i--){
		cs.push_back(as[i]);
		as.pop_back();
	}
}
void atob(){
	sort(as.begin(),as.end(),cmp2);
	for(ll i=as.size()-1;i>=n/2;i--){
		bs.push_back(as[i]);
		as.pop_back();
	}
}
void btoa(){
	sort(bs.begin(),bs.end(),cmp3);
	for(ll i=bs.size()-1;i>=n/2;i--){
		as.push_back(bs[i]);
		bs.pop_back();
	}
}
void btoc(){
	sort(bs.begin(),bs.end(),cmp4);
	for(ll i=bs.size()-1;i>=n/2;i--){
		cs.push_back(bs[i]);
		bs.pop_back();
	}
}
void ctoa(){
	sort(cs.begin(),cs.end(),cmp5);
	for(ll i=cs.size()-1;i>=n/2;i--){
		as.push_back(cs[i]);
		cs.pop_back();
	}
}
void ctob(){
	sort(cs.begin(),cs.end(),cmp6);
	for(ll i=cs.size()-1;i>=n/2;i--){
		bs.push_back(cs[i]);
		cs.pop_back();
	}
}
void input() {
	cin >> n;
	sds.clear();
	sds.resize(n);
	as.clear(), bs.clear(), cs.clear();
	for (ll i = 0; i < n; i++) {
		auto&f = sds[i];
		cin >> f.a >> f.b >> f.c;
		ll mx = max(f.a, max(f.b, f.c));
		if (mx == f.a) as.push_back(i);
		if (mx == f.b) bs.push_back(i);
		if (mx == f.c) cs.push_back(i);
	}
	sort(as.begin(),as.end(),cmp);
	ans=0;
	for(ll i=0;i<n/2;i++){
		ans+=sds[as[i]].a;
	}
	cout<<ans<<endl;
}
int main() {
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	while (T--) {
		input();
	}
	return 0;
}