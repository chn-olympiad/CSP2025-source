#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define int long long
#define MaxN 100005

struct Node{
	int a[5];
	int fir, sec, thi;
	Node(){}
	void init(){
		fir = max(max(a[1], a[2]), a[3]);
		if(fir == a[1]){
			fir = 1;
			if(a[2] > a[3]){
				sec = 2; thi = 3;
			}else sec = 3, thi = 2;
		}else if(fir == a[2]){
			fir = 2;
			if(a[1] > a[3]){
				sec = 1; thi = 3;
			}else sec = 3, thi = 1;
		}else{
			fir = 3;
			if(a[1] > a[2]){
				sec = 1; thi = 2;
			}else sec = 2, thi = 1;
		}
	}
};

int T;
int n, ans;
Node a[MaxN];

void sol(){
	int res = 0;
	int num[5];
	For(i, 0, 5) num[i] = 0;
	priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
//	priority_queue<pair<int, int> > q;
//	queue<int> q2;
	vector<int> v;
	int full = 0;
	int i = 1;
	while(!full && i <= n){
		num[a[i].fir]++;
		res += a[i].a[a[i].fir];
//		cout << "selected " << i << "." << a[i].fir << endl;
		q.push(make_pair(a[i].a[a[i].fir]+a[i].a[a[i].sec], i));
		v.push_back(i);
		if(num[a[i].fir] == n/2){
			full = a[i].fir;
		}
		i++;
	}
//	for(; i <= n; i++){
//		if(a[i].fir == full){
//			int temp = 0, pos = 0;
//			for(auto t : v){
//				int prev = a[i].a[a[i].sec] + a[t].a[a[t].fir];
//				int after = a[i].a[a[i].fir] + a[t].a[a[t].sec];
//				if(prev <= after){
//					if(after - prev > temp){
//						temp = after - prev;
//						pos = t;
//					}
//				}
//			}
//			if(temp == 0){
//				res += a[i].a[a[i].sec];
//			}else{
//				v[pos] = i;
//				res += temp;
//			}
//		}else{
//			res += a[i].a[a[i].fir];
//		}
//	}

	for(; i <= n; i++){
		if(a[i].fir == full){
			int t = q.top().second;
			int prev = a[i].a[a[i].sec] + a[t].a[a[t].fir];
			int after = a[i].a[a[i].fir] + a[t].a[a[t].sec];
			if(prev <= after){
				q.pop();
				q.push(make_pair(a[i].a[a[i].fir]+a[i].a[a[i].sec], i));
				res -= prev;
				res += after;
			}else res += a[i].a[a[i].sec];
		}else{
			res += a[i].a[a[i].fir];
		}
	}
	ans = max(ans, res);
}

int CMP = 1;

bool cmp(Node x, Node y){
	return x.fir == CMP;
}

bool spcmp(Node x, Node y){
	return x.a[1] > y.a[1];
}

int b[35];

void work(){
	int res = 0;
	int num[5];
	For(i, 1, 5) num[i] = 0;
	For(i, 1, n){
		if(b[i]){		//take first
			num[a[i].fir]++;
			res += a[i].a[a[i].fir];
		}else{
			num[a[i].sec]++;
			res += a[i].a[a[i].sec];
		}
	}
	For(i, 1, 3) if(num[i] > n/2) return ;
	ans = max(ans, res);
}

void dfs(int x){
	if(x == n+1){
		work();
		return ;
	}
	b[x] = 0; dfs(x+1);
	b[x] = 1; dfs(x+1);
}

void specialA(){
	sort(a+1, a+1+n, spcmp);
	For(i, 1, n/2) ans += a[i].a[1];
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);

	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		int flag1 = 1;
		For(i, 1, n){
			For(j, 1, 3){
				cin >> a[i].a[j];
			}
			if(a[i].a[2]!=0 || a[i].a[3]!=0) flag1 = 0;
			a[i].init();
		}
		if(flag1){
			specialA();
			cout << ans << endl;
		}else if(n <= 34){
			dfs(1);
			cout << ans << endl;
		}else{
			CMP = 1; sort(a+1, a+1+n, cmp); sol();
			CMP = 2; sort(a+1, a+1+n, cmp); sol();
			CMP = 3; sort(a+1, a+1+n, cmp); sol();
			cout << ans << endl;
		}
	}
    return 0;
}
