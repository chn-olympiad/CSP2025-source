#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

const int N = 1e5 + 86;
ll n,k,sum; // 元素个数、堆上限、答案
struct node{
	ll a,b,c;
}peo[N];

typedef pair<int,int> p; // 用于存储堆中元素<贡献， 编号>
priority_queue<p , vector<p> , greater<p> > A,B,C , temp; // 构造三个反悔堆

inline ll check(char opt){
	if(opt == 'A') return A.top().first;
	if(opt == 'B') return B.top().first;
	return C.top().first;
}

inline void deal(ll pos){
	//dbug(pos);
	//cerr << A.size() << " " << B.size() << " " << C.size() << " " << sum << endl;
	auto [a,b,c] = peo[pos];
	ll maxn = max({a , b , c});
	ll minn = min({a , b , c});
	ll midn = (a + b + c) - maxn - minn;
	//cout << maxn << " " << midn << " " << minn << endl;

	bool o = 0; // 表示是否放入某个集合
	// 处理 maxn
	if(maxn == a){
		if(A.size() < k){
			sum += maxn;
			A.emplace(maxn , pos);
			o = 1;
		}else if(check('A') < maxn){
			sum -= check('A');
			sum += maxn;
			ll temp = A.top().second;
			A.pop();
			A.emplace(maxn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else if(maxn == b){
		if(B.size() < k){
			sum += maxn;
			B.emplace(maxn , pos);
			o = 1;
		}else if(check('B') < maxn){
			sum -= check('B');
			sum += maxn;
			ll temp = B.top().second;
			B.pop();
			B.emplace(maxn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else{
		if(C.size() < k){
			sum += maxn;
			C.emplace(maxn , pos);
			o = 1;
		}else if(check('C') < maxn){
			sum -= check('C');
			sum += maxn;
			ll temp = C.top().second;
			C.pop();
			C.emplace(maxn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}
	if(o) return ;

	// 处理 midn
	if(midn == a){
		if(A.size() < k){
			sum += midn;
			A.emplace(midn , pos);
			o = 1;
		}else if(check('A') < midn){
			sum -= check('A');
			sum += midn;
			ll temp = A.top().second;
			A.pop();
			A.emplace(midn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else if(midn == b){
		if(B.size() < k){
			sum += midn;
			B.emplace(midn , pos);
			o = 1;
		}else if(check('B') < midn){
			sum -= check('B');
			sum += midn;
			ll temp = B.top().second;
			B.pop();
			B.emplace(midn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else{
		if(C.size() < k){
			sum += midn;
			C.emplace(midn , pos);
			o = 1;
		}else if(check('C') < midn){
			sum -= check('C');
			sum += midn;
			ll temp = C.top().second;
			C.pop();
			C.emplace(midn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}

	if(o) return ;

	// 处理 minn
	if(minn == a){
		if(A.size() < k){
			sum += minn;
			A.emplace(minn , pos);
			o = 1;
		}else if(check('A') < minn){
			sum -= check('A');
			sum += minn;
			ll temp = A.top().second;
			A.pop();
			A.emplace(minn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else if(minn == b){
		if(B.size() < k){
			sum += minn;
			B.emplace(minn , pos);
			o = 1;
		}else if(check('B') < minn){
			sum -= check('B');
			sum += minn;
			ll temp = B.top().second;
			B.pop();
			B.emplace(minn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}else{
		if(C.size() < k){
			sum += minn;
			C.emplace(minn , pos);
			o = 1;
		}else if(check('C') < minn){
			sum -= check('C');
			sum += minn;
			ll temp = C.top().second;
			C.pop();
			C.emplace(minn , pos);
			deal(temp); // 将淘汰的进行再处理
			o = 1;
		}
	}
}



int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

	ll T;
	cin >> T;
	while(T--){
		A = B = C = temp; // O(1) clear;
		n = sum = 0;
		cin >> n;
		k = n / 2; // 上限
		for(ll i = 1;i <= n;i++){ // input
			cin >> peo[i].a >> peo[i].b >> peo[i].c;
		}
		for(ll i = 1;i <= n;i++){
			deal(i);
		}
		cout << sum << endl;
		//cerr << endl;
	}

    return 0;
}
