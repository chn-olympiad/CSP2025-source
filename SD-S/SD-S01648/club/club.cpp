#include <bits/stdc++.h>
using namespace std;

int T,n,a[100005][4];
long long ans = 0;

int cnt[4];
bool vis[100005];

class Node{
	public:
		int data;
		int bumen;
		int id;
		Node(){}
		Node(int da,int b,int i){
			data = da;
			bumen = b;
			id = i;
		}
		friend bool operator <(const Node& a,const Node& b){
			return a.data < b.data;
		}
};



void dfs(int cnt[4],int c = 1,long long sum = 0){
	if(c==n+1){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(cnt[i] < n / 2){
			cnt[i]++;
			dfs(cnt,c+1,sum + a[c][i]);
			cnt[i]--;
		}
	}
}

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while(T--){
		int cc[4] = {0,0,0,0};
		ans = 0;
		cin >> n;
		if(n < 30){
			for(int i = 1; i <= n; i++)cin >> a[i][1] >> a[i][2] >> a[i][3];
			dfs(cc);
			cout << ans << '\n';
			continue;
		}
		if(n > 100000){
			int ar[100005];
			for(int i = 1,u,v; i <= n; i++)cin >> ar[i] >> u >> v;
			sort(ar+1,ar+1+n,cmp);
			long long co = 0;
			for(int i = 1; i <= n/2; i++)co+=ar[i];
			cout << co << '\n';
			continue;
		}
		
		
		
		
		
		memset(vis,0,sizeof(vis));
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		priority_queue<Node> q;
		for(int i = 1; i <= n; i++){
			int a,b,c;
			cin >> a >> b >> c;
			q.push(Node(a,1,i));
			q.push(Node(b,2,i));
			q.push(Node(c,3,i));
		}
		while(!q.empty()){
			Node p = q.top();
			q.pop();
			if(vis[p.id])continue;
			if(cnt[p.bumen] == n / 2)continue;
			vis[p.id] = 1;
			ans += p.data;
			cnt[p.bumen]++;
		}
		cout << ans << '\n';
		
	}
	

	return 0;
}

