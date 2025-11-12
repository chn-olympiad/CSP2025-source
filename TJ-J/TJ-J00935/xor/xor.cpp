#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define Pii pair<int,int>
#define Pll pair<ll,ll>
namespace wjx{
void FRE(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
}
//void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int T_T = 1;

int n,k;
int a[500005];
int f[500005];
priority_queue <int> vec[1048580];
vector <pair<int,int> >b;
void get(){
	cin >> n >> k;
	for (int i = 1;i <= n;++i) cin >> a[i];
}
bool cmp(Pii a,Pii b){
	if (a.se == b.se) return a.fi < b.fi;
	return a.se < b.se;
}
void solve(){
//	vec[1].push(1);
//	vec[1].push(2);
//	cout << vec[1].top() << "\n\n";
	f[1] = 0;
	bool flag = true;
	for (int i = 1;i <= n;++i){
		f[i] = f[i - 1] ^ a[i];
		vec[f[i]].push(i);
		if (f[i] == k && flag){
			b.push_back(make_pair(1,i));
			flag = false;
		} 
//		cout << f[i] << '\n';
	}
	int m = f[n] ^ k;
//	cout << "M: " << m << "\n";
	int num = 0;
	flag = true;
	for (int i = n;i >= 1;--i){
		num ^= a[i];
		if (num == k && i != 1 && flag){flag = false;b.push_back(make_pair(i,n));}
		int kkk = num ^ m;
//		cout << num << ' ' << kkk << ": ";
		int left = 0;
		while (!vec[kkk].empty()){
			if (vec[kkk].top() + 1 <= i - 1){
				left = vec[kkk].top();
				break;
			}
			vec[kkk].pop();
		}
		if (left != 0 && left + 1 <= i - 1) b.push_back(make_pair(left + 1,i - 1));
//		cout << i << ' ' << b.size() << "\n";
//		cout << "\n";
	}
	m = b.size();
//	cout << m << "\n";
	sort(b.begin(),b.end(),cmp);
	int right = 0,ans = 0;
	for (int i = 0;i < m;++i){
		if (b[i].fi > right){
			++ans;
			right = b[i].se;
		}
	}
	cout << ans << "\n";
}

signed main(){
//	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve();
	}
	return 0;
}

}

signed main(){
//	wjx::IOS();
	wjx::FRE();
	return wjx::main();
}
/*
rp++
sum ^ a = k
sum ^ k = a

sum ^ (a ^ b) = k
sum ^ k = a ^ b

4 3
2 1 0 3

1 2

b ^ m = a;

m ^ (f ^ b) = k
m ^ k = f ^ b

11010
10011
01001

11010
01001
10011
*/

