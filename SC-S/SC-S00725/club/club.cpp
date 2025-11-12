#include<stdio.h>
inline void read(int &x){
	x = 0;
	char c;
	bool f = 0;
	do{
		c = getchar();
		if(c=='-') f = 1;
	}while(c<'0'||'9'<c);
	while('0'<=c && c<='9'){
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	if(f) x = -x;
}
#include<algorithm> 
using std::sort;
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
constexpr int MAXN = 1e5+5;
//int max3(int x, int y, int z){
//	if(x>=y && x>=z){
//		return x;
//	} else if(y>=x && y>=z){
//		return y;
//	} else{
//		return z;
//	}
//}

struct feel{
	int x,y,z;
	int first, second, fee;
	int id1, id2;
	void init(){
		if(x>=y && x>=z){
			first = x;
			id1 = 1;
			if(y>=z){
				second =  y;
				id2 = 2;
			} else{
				second = z;
				id2 = 3;
			}
		} else if(y>=x && y>=z){
			first = y;
			id1 = 2;
			if(x>=z){
				second = x;
				id2 = 1;
			} else{
				second = z;
				id2 = 3;
			}
		} else{
			first = z;
			id1 = 3;
			if(x>=y){
				second = x;
				id2 = 1;
			} else{
				second = y;
				id2 = 2;
			}
		}
		fee = first - second;
//		printf("The Group {%d,%d,%d} chose fee into %d\n",x,y,z,fee);
	}
	auto operator > (const feel rhs) const{
		return fee > rhs.fee;
	}
} p[MAXN];	// person

#include<queue>
using std::vector;
#include<functional>
using std::greater;
using pq = std::priority_queue<feel,vector<feel>,greater<feel> >;

int n;
unsigned half;

int res;

inline void target(pq &q){
//	printf("half %d\n",half);
	while(q.size() > half){
//		printf("Get out of the Group: {%d,%d,%d}\n",q.top().x,q.top().y,q.top().z);
		res -= q.top().fee;
		q.pop();
	}
}

inline void solve(){
	read(n);
	for(int i=1;i<=n;i++){
		read(p[i].x); read(p[i].y); read(p[i].z);
		p[i].init();
	}
	// the person won't goto place he dislike.
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",p[i].x, p[i].y, p[i].z);
//	}
	res = 0;
	pq q1,q2,q3;
	for(int i=1;i<=n;i++){
		switch (p[i].id1) {
		case 1:
			q1.push(p[i]);
			break;
		case 2:
			q2.push(p[i]);
			break;
		case 3:
			q3.push(p[i]);
		}
		res += p[i].first;
	}
	half = n>>1;
	if(q1.size() > half){
		target(q1);
	} else if(q2.size() > half){
		target(q2);
	} else if(q3.size() > half){
		target(q3);
	}
	printf("%d\n",res);
}

int main(){
#ifndef IO
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#else
	freopen("club5.in","r",stdin);
#endif
	int T;
	read(T);
	while(T--) solve();
	return 0;
}