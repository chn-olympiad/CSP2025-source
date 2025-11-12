#include <bits/stdc++.h>
#define int long long    //3 years oi a void, no long long would see father^INF
using namespace std;

//EZ!
//i would get 3rd prize if my program has no mistakes

//fuck
//this problem is the one i'm only able to solve
//but i think i can get 116pts
//hoping this score can bring a 3rd prize



//From miles away
//Flew to find how it is ending u(ending u)
//----Chronicle A(en. ver)

const int maxn = 1e5+5;
int ans;
struct node{
	int a, b, c;
	int maxV, second_maxV, target, dis;
	node(){
	}
	node(int a, int b, int c){
		this->a = a;
		this->b = b;
		this->c = c;
		int tmp[] = {a, b, c};
		sort(tmp, tmp+3);
		maxV = tmp[2];
		second_maxV = tmp[1];
		dis = maxV-second_maxV;
		if (maxV == a){
			target = 1;
			return;
		}
		if (maxV == b){
			target = 2;
			return;
		}
		target = 3;
		return;
	}
	bool operator<(const node &another) const{
		return dis < another.dis;
	}
}nodes[maxn];
int n, t;
vector<node> v[4];
//move grab jump dash
//super_dash hyper_dash wave_dash dream_jump wall_bounce
//reversed_super_dash reversed_hyper_dash reversed_wave_dash dream_grab
//neutral_jump
//ultra grounded_ultra delayed_ultra multi_ultra
signed main(){
	freopen("club.in", "r", stdin);//DON'T FORGET WRITE IT!
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--){
		ans = 0;
		memset(nodes, 0, sizeof nodes);
		v[1] = vector<node>();
		v[2] = vector<node>();
		v[3] = vector<node>();
		cin >> n;
		for (int i = 1; i <= n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			nodes[i] = node(a, b, c);
			v[nodes[i].target].push_back(nodes[i]);
			ans += nodes[i].maxV;
		}
		for (int i = 1; i <= 3; i++){
			int length = v[i].size();
			if (length > n/2){
				sort(v[i].begin(), v[i].end());
				for (int j = 0; j < length-n/2; j++){
					ans -= v[i][j].maxV;
					ans += v[i][j].second_maxV;
				}
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
