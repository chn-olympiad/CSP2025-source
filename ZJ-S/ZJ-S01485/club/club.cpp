#include <algorithm>
//#include <bitset>
#include <cctype>
#include <cstdio>
#include <queue>
#ifdef LOCALDEBUG
#define fex(a, b)
#else
#define fex(a, b) freopen(a, "r", stdin);freopen(b, "w", stdout)
#endif
using namespace std;

long long read() {
	long long res=0, f=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	while(isdigit(c)) res=res*10+c-'0', c=getchar();
	return res*f;
}

//long long mx(long long a, long long b, long long c) {
//	if(a>b)return a>c?a:c;
//	return b>c?b:c;
//}

struct node {
	long long a;
	long long b;
	long long c;
};

struct node1 {
	long long a;
	long long b;
	long long c;
};

struct node2 {
	long long a;
	long long b;
	long long c;
};

struct node3 {
	long long a;
	long long b;
	long long c;
};

bool operator <(node1 x, node1 y) {
	if(x.a-max(x.b, x.c)==y.a-max(y.b, y.c))return x.a<y.a;
	return x.a-max(x.b, x.c)>x.b-max(y.b, y.c);
}

bool operator <(node2 x, node2 y) {
	if(x.b-max(x.a, x.c)==y.b-max(y.a, y.c))return x.b<y.b;
	return x.b-max(x.a, x.c)>y.b-max(y.a, y.c);
}

bool operator <(node3 x, node3 y) {
	if(x.c-max(x.b, x.a)==y.c-max(y.b, y.a))return x.c<y.c;
	return x.c-max(x.b, x.a)>y.c-max(y.b, y.a);
}

//bool operator <(node1 x, node1 y) {
//	if(x.a==y.a)return max(x.b, x.c)<max(y.b, y.c);
//	return x.a<y.a;
//}
//
//bool operator <(node2 x, node2 y) {
//	return x.a<y.a;
//	return max(x.a, x.c)<max(y.a, y.c);
//}
//
//bool operator <(node3 x, node3 y) {
//	return x.a<y.a;
//	return max(x.a, x.b)<max(y.a, y.b);
//}

long long nodem(node x) {
	if(x.a>x.b)return x.a>x.c?1:3;
	return x.b>x.c?2:3;
}

node1 make_node1(long long a, long long b, long long c) {
	node1 d;
	d.a=a;
	d.b=b;
	d.c=c;
	return d;
}

node2 make_node2(long long a, long long b, long long c) {
	node2 d;
	d.a=a;
	d.b=b;
	d.c=c;
	return d;
}

node3 make_node3(long long a, long long b, long long c) {
	node3 d;
	d.a=a;
	d.b=b;
	d.c=c;
	return d;
}

//bitset<100005> d[5];
long long T;
unsigned long long n;
//long long a[100005][5];
//long long f[100005][5], g[100005][5][5];
//long long cnt, c1, c2, c3;
long long ans;
node c[100005];
priority_queue<node1> p1;
priority_queue<node2> p2;
priority_queue<node3> p3;

int main(void) {
	fex("club.in", "club.out");
	T=read();
	while(T--) {
		n=read();
//		c1=c2=c3=cnt=0;
		ans=0;
//		d[1].reset();
//		d[2].reset();
//		d[3].reset();
//		d.reset();
//		while(!q1.empty())q1.pop();
//		while(!q2.empty())q2.pop();
//		while(!q3.empty())q3.pop();
		for(unsigned int i = 1; i <= n; ++i) {
//			for(int j = 1; j <= 3; ++j)f[i][j]=0;
			c[i].a=read();c[i].b=read();c[i].c=read();
//			for(int j = 1; j <= 3; ++j)for(int k = 1; k <= 3; k++)g[i][j][k]=0;
//			q1.push(make_node(i, a[i][1]));
//			q2.push(make_node(i, a[i][2]));
//			q3.push(make_node(i, a[i][3]));
		}
//		sort(c+1, c+n+1);
//		for(int i = 1; i <= n; i++) {
//			a[i][1]=c[i].a;
//			a[i][2]=c[i].b;
//			a[i][3]=c[i].c;
//		}
//		for(int i = 1; i <= n; i++) {
//			for(int j = 1; j <= 3; j++) {
//				for(int k = 1; k <= 3; k++) {
//					if(g[i-1][k][j]<n/2&&f[i-1][k]+a[i][j]>=f[i][j]) {
//						g[i][j][1]=g[i-1][k][1];
//						g[i][j][2]=g[i-1][k][2];
//						g[i][j][3]=g[i-1][k][3];
//						g[i][j][j]++;
//						f[i][j]=f[i-1][k]+a[i][j];
//						d[j][i]=1;
//					}
//				}
//				if(!d[j][i])f[i][j]=-1e9, g[i][j][1]=g[i][j][2]=g[i][j][3]=1e9;
//			}
//		}
////		for(int i = 1; i <= n; i++) {
////			for(int j = 1; j <= 4; j++)printf("%lld ", f[i][j]);
////			putchar('\n');
////		}
////		for(int i = 1; i <= n; i++) {
////			for(int j = 1; j <= 3; j++) {
////				printf("%d - %d: %lld %lld %lld\n", i, j, g[i][j][1], g[i][j][2], g[i][j][3]);
////			}
////		}
//		printf("%lld\n", mx(f[n][1], f[n][2], f[n][3]));
		for(unsigned int i = 1; i <= n; i++) {
			long long g=nodem(c[i]);
			if(g==1) {
				p1.push(make_node1(c[i].a, c[i].b, c[i].c));
				if(p1.size()>n/2) {
					node1 e=p1.top();
					p1.pop();
					if(e.b>e.c)p2.push(make_node2(e.a, e.b, e.c));
					else       p3.push(make_node3(e.a, e.b, e.c));
				}
			}
			else if(g==2) {
				p2.push(make_node2(c[i].a, c[i].b, c[i].c));
				if(p2.size()>n/2) {
					node2 e=p2.top();
					p2.pop();
					if(e.a>e.c)p1.push(make_node1(e.a, e.b, e.c));
					else       p3.push(make_node3(e.a, e.b, e.c));
				}
			}
			else {
				p3.push(make_node3(c[i].a, c[i].b, c[i].c));
				if(p3.size()>n/2) {
					node3 e=p3.top();
					p3.pop();
					if(e.a>e.b)p1.push(make_node1(e.a, e.b, e.c));
					else       p2.push(make_node2(e.a, e.b, e.c));
				}
			}
		}
		while(!p1.empty()) {
			ans+=p1.top().a;p1.pop();
		}
		while(!p2.empty()) {
			ans+=p2.top().b;p2.pop();
		}
		while(!p3.empty()) {
			ans+=p3.top().c;p3.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
} // O(n)
// CHTH!
