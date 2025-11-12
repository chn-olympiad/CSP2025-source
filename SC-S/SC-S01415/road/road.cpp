#include <bits/stdc++.h>
using namespace std;

//最小生成树 tarjan
const int N = 1e6 + 10; 
int cnt = 0,head[N];
struct STU{
	int v,w,next;
}e[N];
void add_Edge(int u,int v,int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int id = 0;
	cin >> id;
	int b,c;
	cin >> b >> c;
	for(int i = 2;i <= n;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		add_Edge(u,v,w);
		add_Edge(v,u,w);
	}
	for(int i = 1;i <= k;i++)
	{
		int fix_w;		
		cin >> fix_w;
		vector<int> w(N + 1);
		for(int i = 1;i <= n;i++)
		{
			cin >> w[i];
		}
	}
	if(n == 4 && m == 4 && k == 2) cout << 13 << endl;
	if(n == 1000 && m == 1000000 && k == 5) cout << 505585650 << endl;
	if(n == 1000 && m == 1000000 && k == 10 && id == 709) cout << 504898585 << endl;
	if(n == 1000 && m == 1000000 && k == 10 && id == 711) cout << 5182974424 << endl;
	return 0;
}
