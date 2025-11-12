#include<bits/stdc++.h>
using namespace std;

#define ll long long

namespace wjx{

int T_T = 1;

void FRE(){
	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
}
void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int n;
struct node{
	int a,b,c;
	int mx1,mx2,mx3;
	int b1,b2,b3;
}a[100005];
struct Nd{
	int val,id;
};
bool cmp_Nd(Nd a,Nd b){
	return a.val > b.val;
}
void get(){
	cin >> n;
	for (int i = 1;i <= n;++i){
		cin >> a[i].a >> a[i].b >> a[i].c;
		Nd b[4] = {{0,0},{a[i].a,1},{a[i].b,2},{a[i].c,3}};
		sort(b + 1,b + 3 + 1,cmp_Nd);
		a[i] = (node){a[i].a,a[i].b,a[i].c,b[1].val,b[2].val,b[3].val,b[1].id,b[2].id,b[3].id};
	}
}
struct nd{
	int id,cnt;
	void clear(int idx){
		id = idx;
		cnt = 0;
	}
}cnt[4];
bool cmp(nd x,nd y){
	return x.cnt > y.cnt;
}
bool O1(nd x,nd y){
	return x.id < y.id;
}
bool O2(int x,int y){
	return a[x].mx1 - a[x].mx2 < a[y].mx1 - a[y].mx2;
}
bool O3(int x,int y){
	return a[x].mx2 - a[x].mx3 < a[y].mx2 - a[y].mx3;
}
vector <int> vec[4];
int f[4];
int calc(){
	int sum = 0;
	for (int i = 1;i <= 3;++i){
		int sz = vec[i].size();
		for (int j = f[i];j < sz;++j){
			if (a[vec[i][j]].b1 == i) sum += a[vec[i][j]].mx1;
			else if (a[vec[i][j]].b2 == i) sum += a[vec[i][j]].mx2;
			else sum += a[vec[i][j]].mx3; 
		}
	}
	return sum;
}
void solve(){
	cnt[1].clear(1);cnt[2].clear(2);cnt[3].clear(3);
	vec[1].clear();vec[2].clear();vec[3].clear();
	f[0] = f[1] = f[2] = f[3] = 0;
	for (int i = 1;i <= n;++i){
		cnt[a[i].b1].cnt++;
		vec[a[i].b1].push_back(i);
	}
	sort(cnt + 1,cnt + 4,cmp);
	if (cnt[1].cnt <= n / 2){
		int ans = calc();
//		for (int i = 1;i <= n;++i) ans += a[i].mx1;
		cout << ans << "\n";
		return ;
	}else{
		int k = cnt[1].cnt - n / 2;
		int id = cnt[1].id;
		cnt[1].cnt -= n / 2;
		sort(vec[id].begin(),vec[id].end(),O2);
		sort(cnt + 1,cnt + 4,O1);
		for (int i = 0;i < k;++i){
			++cnt[a[vec[id][i]].b2].cnt;
			vec[a[vec[id][i]].b2].push_back(vec[id][i]);
		}
		f[id] = k;
		sort(cnt + 1,cnt + 4,cmp);
		if (cnt[1].cnt <= n / 2){
			int ans = calc();
			cout << ans << "\n";
		}else{
			k = cnt[1].cnt - n / 2;
			int id = cnt[1].id;
			cnt[1].cnt -= n / 2;
			sort(vec[id].begin(),vec[id].end(),O3);
			sort(cnt + 1,cnt + 4,O1);
			for (int i = 0;i < k;++i){
				++cnt[a[vec[id][i]].b3].cnt;
				vec[a[vec[id][i]].b3].push_back(vec[id][i]);
			}
			f[id] = k;
			int ans = calc();
			cout << ans << "\n";
		}
	}
}

signed main(){
	cin >> T_T;
	while (T_T--){
		wjx::get();
		wjx::solve(); 
	}
}

}

signed main(){
	wjx::IOS();
	wjx::FRE();
	return wjx::main();
}//rp++
//15:44
