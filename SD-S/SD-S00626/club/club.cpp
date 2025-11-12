#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<unordered_map>

using namespace std;

struct Node{
	long long max1;
	long long max2;
	int max1id;
	int max2id;
	bool friend operator < (Node a, Node b){
		return (a.max1 - a.max2) > (b.max1 - b.max2);
	}
}node[100005], temp[4];

long long n, ans;
int T;

bool cmpsort(Node a, Node b){
	return a.max1 > b.max1;
}

//bool cmpque(int a, int b){
//	return (node[a].max1 - node[a].max2) > (node[b].max1 - node[b].max2);
//}

priority_queue<Node> q[4];//id

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		for(int i = 1; i <= 3; i++)
			while(!q[i].empty())
				q[i].pop();
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
		{
			temp[1].max1id = 1;
			temp[2].max1id = 2;
			temp[3].max1id = 3;
			scanf("%lld%lld%lld", &temp[1].max1, &temp[2].max1, &temp[3].max1);
			sort(temp + 1, temp + 1 + 3, cmpsort);
			node[i] = {temp[1].max1, temp[2].max1, temp[1].max1id, temp[2].max1id};
		}
		for(int i = 1; i <= n; i++)
		{
			int op = node[i].max1id;
			q[op].push(node[i]);
			ans += node[i].max1;
			if(int(q[op].size()) > n / 2)
			{
				Node p = q[op].top();
				q[op].pop();
				q[p.max2id].push(p);
				ans -= p.max1;
				ans += p.max2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
