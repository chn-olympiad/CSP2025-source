#include <cstdio>
#include <queue>
#include <bitset>
#include <cctype>
using namespace std;
#define LL long long
#define x first
#define y second

typedef pair<LL,pair<int,int> > PC;

const int N = 10020,M = (1000000 + 10000 * 10 + 100) * 2;

int n,m,k,h[N],ne[M],e[M],idx = 1;
LL w[M],del[11];
bitset<N> done(0);

void add(int a,int b,LL c){
	ne[idx] = h[a];
	e[idx] = b;
	h[a] = idx;
	w[idx++] = c;
}

LL oper(){
	LL result = 0;
	int de = n;
	priority_queue<PC,vector<PC>,greater<PC> > q;
	q.push({0,{1,1}});
	while (de){
		PC p = q.top();
		q.pop();
		if (done[p.y.y])
			continue;
		if (p.y.y <= n)
			de--;
		else
			del[p.y.y - n - 1] = p.x;
		if (p.y.x > n)
			del[p.y.x - n - 1] = 0;
		result += p.x;
		done[p.y.y] = true;
		for (int i = h[p.y.y];i;i = ne[i]){
			if (done[e[i]])
				continue;
			q.push({w[i],{p.y.y,e[i]}});
		}
	}
	
	for (int i = 0;i < k;i++)
		result -= del[i];
	
	return result;
}

LL read(){
	LL out = 0;
	char in = getchar();
	while (!isdigit(in))
		in = getchar();
	while (isdigit(in)){
		out = out * 10 + (in - '0');
		in = getchar();
	}
	return out;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int a,b;
	LL c;
	n = read();
	m = read();
	k = read();
	
	for (int i = 0;i < m;i++){
		a = read();
		b = read();
		c = read();
		add(a,b,c);
		add(b,a,c);
	}
	
	for (int i = 1;i <= k;i++){
		a = read();
		for (int j = 1;j <= n;j++){
			c = read();
			add(j,n + i,c + a);
			add(n + i,j,c);
		}
	}
	
	printf("%lld",oper());
	
	return 0;
}


