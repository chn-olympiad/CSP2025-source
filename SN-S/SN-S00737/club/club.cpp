#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 1e6 + 5;
const long long NINF = 0xc0c0c0c0c0c0c0c0;
struct Node{
	long long first, second;
	int fid, sid;
}nodes[MAXN];
long long cnt[5], a[5], vis[MAXN];
int t, n, pos;

bool cmp1(Node a, Node b){return a.first > b.first;}
bool cmp2(Node a, Node b){return a.first - a.second < b.first - b.second;}

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while(t--){
		n = read();
		for(int i = 1, mxid, smxid; i <= n; i++){
			a[1] = read(), a[2] = read(), a[3] = read();
			a[0] = NINF, mxid = smxid = 0;
			for(int j = 1; j <= 3; j++)
				if(a[j] > a[mxid]) smxid = mxid, mxid = j;
				else if(a[j] > a[smxid]) smxid = j;
			nodes[i].first = a[mxid], nodes[i].second = a[smxid];
			nodes[i].fid = mxid, nodes[i].sid = smxid;
		}
		sort(nodes + 1, nodes + 1 + n, cmp1);
		memset(vis, 0, sizeof(vis));
		cnt[1] = cnt[2] = cnt[3] = 0;
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			if(vis[i] == 0) 
				vis[i] = 1, cnt[nodes[i].fid]++, 
				ans += nodes[i].first;
		if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2){
			cout<< ans<< "\n"; continue;
		}
		if(cnt[1] > n / 2) pos = 1;
		else if(cnt[2] > n / 2) pos = 2;
		else pos = 3;
		sort(nodes + 1, nodes + 1 + n, cmp2);
		for(int i = 1; cnt[pos] > n / 2; i++){
			if(nodes[i].fid == pos)
				ans -= nodes[i].first - nodes[i].second, cnt[pos]--;
		}
		cout<< ans<< "\n";
	}
	fclose(stdin); fclose(stdout);
	return 0;
} 
