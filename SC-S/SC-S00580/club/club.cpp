#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t , n , ans;
struct node {
	ll a , b , c , maxn;
	bool used = 0;
}e[10010];

struct stack_my {
	ll s[10010];
	ll head = 1;
	
	void insert_x(ll x) {
		s[head ++] = x;
	}
	void pop_x() {
		head --;
	}
	ll top_x(ll x) {
		return s[head];
	}
	bool empty() {
		if(head == 1) {
			return 0;
		} else {
			return 1;
		}
		
	}
	void m_empty() {
		head = 0;
	}
};

stack_my as , bs , cs;

bool cmpa(node x , node y) {
	return x.a > y.a;
}
bool cmpb(node x , node y) {
	return x.b > y.b;
}
bool cmpc(node x , node y) {
	return x.c > y.c;
}

int main() {
	freopen("club.in" , "w" , stdin);
	freopen("club.out" ,"r" , stdout);
	scanf("%lld" , &t);
	while(t --) {
		ans = 0;
		scanf("%lld" , &n);
		for(ll i = 1;i <= n;i ++) {
			scanf("%lld %lld %lld" , &e[i].a , &e[i].b , &e[i].c);
			e[i].maxn = max(e[i].a , max(e[i].b , e[i].c));
		}
		
		for(ll i = 1;i <= n;i ++) {
			as.insert_x(e[i].a);
			if(e[i].maxn == e[i].a) {
				if(as.head > (n / 2)) {
					e[i].maxn = max(e[i].b , e[i].c);
					as.pop_x();
				}
				
			}
			if(e[i].maxn == e[i].b) {
				bs.insert_x(e[i].b);
				if(bs.head > (n / 2)) {
					e[i].maxn = max(e[i].a , e[i].c);
					bs.pop_x();
				}
				
			}
			if(e[i].maxn == e[i].c) {
				cs.insert_x(e[i].c);
				if(cs.head > (n / 2)) {
					e[i].maxn = max(e[i].a , e[i].b);
					cs.pop_x();
				}
				
			}
		}
		
		for(ll i = 1;i <= as.head;i ++) {
			ans += as.s[i];
		}
		for(ll i = 1;i <= bs.head;i ++) {
			ans += bs.s[i];
		}
		for(ll i = 1;i <= cs.head;i ++) {
			ans += cs.s[i];
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
